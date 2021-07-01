bool check(long long a, long long b, long long x, vector<int>& c){
    long long cur = 0, n = c.size(), cnt = 1;
    for(int i=0;i<n;i++){
        cur += (long long)(b)*(long long)(c[i]);
        if(cur>x){
            cur = (long long)(b)*(long long)(c[i]);
            cnt++;
        }
    }
    return cnt<=a;
}
int Solution::paint(int a, int b, vector<int> &c) {
    long long l = b*(*max_element(c.begin(),c.end())), r = 1000000000000000000;
    while(r>l){
        long long m = l+(r-l)/2;
        if(check(a,b,m,c)) r = m;
        else l = m+1;
    }
    return (l%10000003);
}