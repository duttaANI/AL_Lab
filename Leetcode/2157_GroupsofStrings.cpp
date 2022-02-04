// TLE but worth thinking

//standard disjoint set union class 
class DSU
{
    vector<int> par,rank;
    public:
    DSU(int N)
    {
        par.resize(N);
        rank.resize(N);
        for(int i=0;i<N;i++) par[i] = i , rank[i] = 0;
    }
    
	//function to find parent of u , with path compression
    int findPar(int u)
    {
        if(u == par[u]) return u;
        
        return par[u] = findPar(par[u]);
    }
    
	//function to join u and v based on their ranks
    void unon(int u,int v)
    {
        u = findPar(u) , v = findPar(v);
        
        if(rank[u] > rank[v])
            par[v] = u;
        else if(rank[u] < rank[v])
            par[u] = v;
        else
        {
            par[u] = v;
            rank[v]++;
        }
        
        // par[u] = v;
    }
};

class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        int n = size(words);
        DSU uf(n+1);
        
		//we make two maps, one to store hash of words, other to store hash of words with 1 char deleted
        unordered_map<int,int> mp,delMap;
        
        for(int i=0;i<n;i++)
        {
            int hash = 0;
			//firstly we calculate hash of current word
			//How to calculate hash ?
			//suppose we have a binary representation 0000000....26 length
			//now if current word has character 'a' , we know 'a' - 'a' = 0 -> make 0th bit set
			//similarly for other characters too , now we are given that in one word there won't be 
			//multiple instances of same character , we can use this method
            for(auto &ch : words[i]) hash |= 1<<(ch-'a');
            
            for(int j=0;j<26;j++)
            {
				//if jth bit is set , we will try to search the string deleting this character
                if(hash >> j & 1)
                {
					//unset the jth bit
                    int t_hash = hash ^ (1<<j);
					
					//now we search in both maps and if match found then connect current idx with matched hash idx
                    if(mp.count(t_hash)) uf.unon(mp[t_hash],i);
                    if(delMap.count(t_hash)) uf.unon(delMap[t_hash],i);
                    else delMap[t_hash] = i;
                }
                else //else we'll try to add this character
                {
					// make jth bit set
                    int t_hash = hash | (1<<j);
					//search in map, if found then connect both
                    if(mp.count(t_hash)) uf.unon(mp[t_hash],i);
                }
            }
            
			//store connect hash in our map
            mp[hash] = i;
        }
        
		//map to store all the parents along with their frequencies
        unordered_map<int,int> res;
        for(int i=0;i<n;i++)
        {
            int p = uf.findPar(i);
            res[p]++;
        }
        
		//variable to store freq of most occurring parent
        int mx = 0;
        for(auto &it : res)
        {
            mx = max(mx,it.second);
        }
        
		//variable to store size of res ,i.e., total no. of parents
        int sz = size(res);
        
        return {sz,mx};
    }
};