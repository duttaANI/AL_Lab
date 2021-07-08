vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    

    vector<vector<int>> ans;
    unordered_map<string,vector<int> > mp;
    int n = A.size();
    for(int i=0;i<n;++i){
        string str = A[i];
        sort(str.begin(),str.end());
        mp[str].push_back((i+1));
    }
    
    unordered_map <string,int> vis;
    
    for( int i=0;i<n;++i){
        string str = A[i];
        sort(str.begin(),str.end());
        if( mp[str].size()>0 && !vis[str]){
            ans.push_back( mp[str] );
            vis[str] = 1;
        }
    } 
    return ans;
}