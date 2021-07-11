bool cmp(string a,string b){
    string s1 = a+b;
    string s2 = b+a;
    return s1>s2;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<string> S;
    int n = A.size();
    for(int i=0;i<n;++i){
        S.push_back(to_string(A[i]));
    }
    sort(S.begin(),S.end(),cmp);
    
    if(S[0]=="0") return "0";
    
    string ans = "";
    for(int i=0;i<n;++i){
        ans += S[i];
    }
    return ans;
}