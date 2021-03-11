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
 
 void dfs(vector<vector<int>>& ans, vector<int>& temp, int start, int target, vector<int>& candidates) {
        
    if( 0==target ) {
        string s = V(temp);
        if(mp.find(s)!=mp.end()){
            return ;
        }
        ans.push_back(temp);
        mp[s] = 1;
        return ;
    } 
    
    for (int i=start; i<candidates.size(); ++i) {  
        
        if(candidates[i]>target) return ;
        
        temp.push_back(candidates[i]);
        
        dfs(ans, temp, i, target-candidates[i], candidates);
      
        temp.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &candidates, int target) {
    mp.clear();
    sort(candidates.begin(),candidates.end());
        
    vector<vector<int>> ans; vector<int> temp;
 
    dfs(ans, temp, 0, target, candidates);
     
    return ans;
}
