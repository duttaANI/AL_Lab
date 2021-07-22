bool isPalin(string s, int l, int r){
    while( l<r  ){
        if( s[l++]!=s[r--]  ) {
            return 0;
        }
    }
    return 1;
}

void dfs(vector<vector<string> >& res, string s, int start,vector<string>& cur ){
    int n = s.size();
    if( start == n  ){
        res.push_back(cur);
    }
    
    for(int i=start;i<n;++i){
        if(  isPalin(s,start,i) ){
            cur.push_back(s.substr(start,i-start+1));
            dfs(res,s,i+1,cur);
            cur.pop_back();
        }
    }
}


vector<vector<string> > Solution::partition(string s) {
    vector<vector<string> > res;
    vector<string> cur;
    
    dfs(res,s,0,cur);
    
    
    return res;
}