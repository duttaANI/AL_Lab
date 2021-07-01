#define ll long long
ll int func ( vector<int> &A, int h  ){
    ll int ans = 0;
    for(int i=0;i<A.size();++i){
        ans += max(0, A[i]-h );
    }
    // cout << " h " << h << "  ans " << ans << endl;
    return ans;
}


int Solution::solve(vector<int> &A, int B) {
    
    int mx = 0,n = A.size();
    for(int i=0;i<n;++i){
        mx = max({mx,A[i]});
    }
    
    int l=0; int h = mx;
    ll int prvmid;
    while( l<h ){
        ll int mid = l+(h-l)/2;
        if(mid==prvmid){
            break;
        }
        ll int woodcut = func(A,mid);
        if( woodcut == B  ){
            return mid;
        }
        if( woodcut > B ){
            l = mid;
        }
        if( woodcut < B  ){
            h = mid;
        }
        
        // cout << l << " " << h << endl;
        prvmid = mid;
    }
    
    return l;
}
