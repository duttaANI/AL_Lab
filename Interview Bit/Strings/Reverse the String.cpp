string Solution::solve(string A) {
    stack<string> s;
    int n = A.size();
    for(int i=0;i<n;++i){
        string temp = "";
        while(A[i]!=' ' && i<n){
            temp += A[i];++i;
        }
        if(temp.size()!=0)
            s.push(temp);
    }
    
    string res = "";
    while(s.size()){
        res += s.top(); s.pop();
        res+= ' ';
    }
    res.pop_back();
    return res;
}