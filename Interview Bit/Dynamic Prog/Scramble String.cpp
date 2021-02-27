// https://www.youtube.com/watch?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&v=VyHEglhbm-A&feature=emb_logo
bool solve(string a, string b,unordered_map<string,int>& mp){
    if(a.compare(b)==0) return 1;
    if(a.size()<=1)return 0; // empty child is not allowed
    int n = a.size();
    
    string key = a + " " + b;
    if(mp.find(key)!=mp.end()){
        return mp[key];
    }
    bool flag=false;
    for(int i=1;i<n;++i){
        // swap
        int swp = solve(a.substr(0,i),b.substr(n-i,i),mp) && solve(a.substr(i,n-i),b.substr(0,n-i),mp);
        int nswp = solve(a.substr(0,i),b.substr(0,i),mp) && solve( a.substr(i,n-i),b.substr(i,n-i),mp);
        if( swp || nswp ){
            flag= true;
        }
    }
    mp[key] = flag;
    return mp[key];
}

int Solution::isScramble(const string a, const string b) {
    int n = a.size(),m= b.size();
    if(n!=m)return 0;
    if(n==m && m==0) return 1;
    unordered_map<string,int> mp;
    return solve(a,b,mp);
}
