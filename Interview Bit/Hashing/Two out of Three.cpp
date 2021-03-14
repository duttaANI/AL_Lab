vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    vector<int> ans;
    set<int> res;
    unordered_map<int,int> mp1,mp2,mp3;
    for(int i=0;i<A.size();++i){
        mp1[A[i]]++;
    }
    for(int i=0;i<B.size();++i){
        mp2[B[i]]++;
        if(mp1.find(B[i])!=mp1.end()){
            res.insert(B[i]);
        }
    }
    for(int i=0;i<C.size();++i){
       
        if(mp1.find(C[i])!=mp1.end()){
            res.insert(C[i]);
        }
        if(mp2.find(C[i])!=mp1.end()){
            res.insert(C[i]);
        }
    }
    
    for( auto i : res ){
        ans.push_back(i);
    }
    return ans;
}
