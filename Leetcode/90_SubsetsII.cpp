class Solution {
public:
    
    unordered_map<string,int> mp;

    string V(vector<int>& vec){
        int n = vec.size();
        string s= "";
        for(int i=0;i<n;++i){
            s += vec[i]-'0';
            s += " "; 
        }
        return s;
    }

    void subset(vector<int> &A,vector<vector<int>> &ans,vector<int> temp,int index)
    {
        //insert 
        string s = V(temp);
        if(mp.find(s)!=mp.end()){
            return ;
        }
        ans.push_back(temp);
        mp[s] = 1;

        for(int i=index;i<A.size();i++)
        {
            temp.push_back(A[i]); // include

            subset(A,ans,temp,i+1); // i+1 , include / exclude for next element
            temp.pop_back(); // exclude
        }
        // cout << endl;
        return;
    }
 
    vector<vector<int>> subsetsWithDup(vector<int>& A ) {
        mp.clear();
        vector<vector<int>> ans;
        sort(A.begin(),A.end());
        int index=0;
        vector<int> temp;
        subset(A,ans,temp,index);
        return ans;
    }
};