int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    vector<int> in(n,0);
    vector<int> out(n,0);
    for(int i=0;i<n;++i){
        in[i] = A[i][0];
        out[i] = A[i][1];
    }
    sort(in.begin(),in.end());
    sort(out.begin(),out.end());
    
    int cur = 0;
    int ans = 0;
    int p1=0,p2=0;
    while( p1<n && p2<n ){
        if( in[p1]<out[p2]  ){
            ++cur;
            ++p1;
        }
        else{
            --cur;
            ++p2;
        }
        ans = max({ans,cur});
    }
    return ans;
}