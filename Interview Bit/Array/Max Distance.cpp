int Solution::maximumGap(const vector<int> &A) {
    // sort(A.begin(),A.end());
    
    int n = A.size();
    vector<int> suff(n,0);
    
    suff[n-1] = A[n-1];
    for(int i=n-2; i>=0;--i){
        suff[i] = max({ suff[i+1],A[i] });
    }
    
    int i=0,j=0;
    int ans = 0; 
    while(j<n){
        if( j<n && A[i]<=suff[j] ){
            ans = max({j-i, ans  });
            ++j;
        }
        else{
            ++i;
        }
    }
    return ans;
}