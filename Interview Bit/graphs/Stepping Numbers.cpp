vector<int> Solution::stepnum(int A, int B) {
    
    queue<int> q;
    for(int i=0;i<=9; ++i){
        q.push(i);
    }
    
    set<int> ans;
    vector<int> res;
    
    while(!q.empty()){
        int frnt = q.front();
        q.pop();
        
        if( frnt<=B && frnt>=A ){
            ans.insert(frnt);
        }else if(frnt>B){
            continue;
        }
        
        int f1 = frnt*10 + ( frnt%10 -1);
        int f2 = frnt*10 + ( frnt%10 +1);
        if( (frnt)%10!=0 ){
            q.push(f1);
        }
        if( (frnt+1)%10!=0 ){
            q.push(f2);
        }
    }
    for(int i : ans){
        res.push_back(i);
    }
    return res;
}
