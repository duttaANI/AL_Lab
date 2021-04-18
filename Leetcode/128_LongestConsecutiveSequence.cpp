// union find

class Solution {
public:
    
    unordered_map<int,int> mp;
    static const int mxN = 1e5+5;
    int p[mxN],size[mxN];
    
    int find(int x){
        return p[x]^x?p[x]=find(p[x]):x;
    }
    
    void join(int x, int y){
        int a,b;
        if( (a=find(x)) == (b=find(y)) ){
            return ;
        }
        if( size[a]>size[b] ) swap(a,b);
        p[a] = b;
        size[b] += size[a];
        return ;
    }
    
    int longestConsecutive(vector<int>& nums) {
        int i,j, n = nums.size();
        for(int i=0;i<100005;++i){
            p[i]=i;
            size[i]=1;
        }
        for(i=0;i<n;++i){
            if(mp.count(nums[i]) ) continue;
            if( mp.count(nums[i]-1) ){
                join( mp[nums[i]-1], i );
            }
            if( mp.count(nums[i]+1) ){
                join( mp[nums[i]+1], i );
            }
            mp[nums[i]] = i;
        }
        int ans = 0;
        for(i=0;i<n;i++){
            ans=max(ans,size[i]);
        }
        return ans;
        
    }
};

//set
class Solution {
public:
    int longestConsecutive(vector<int>& num) {
        set<int> s;
        for(int i : num){
            s.insert(i);
        }
        int longestStreak = 0;
        for(int n : s){
            if(s.find(n-1)==s.end()){
                int curNum = n;
                int curStreak =1;
                
                while(s.find(curNum+1)!=s.end()){
                    curNum += 1;
                    curStreak +=1;
                }
                
                longestStreak = max({longestStreak,curStreak});
            }
        }
        return longestStreak;
    }
};
