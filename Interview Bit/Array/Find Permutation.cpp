vector<int> Solution::findPerm(const string A, int B) {
    vector<int> ans(B,0);

    vector<int> num(B,0);
    for(int i=0;i<B;++i){
        num[i]=i+1;
    }
    

    // two pointer

    int n = B-1;
    
    int l=0,r=0,cur=0;

    for(int i=0;i<=n;++i){

        if(A[i]=='I'){
            ans[cur++]=num[i];
            // cout << i << " 1\n";
        }
        else{
            l=i;
            while( A[i]=='D' && i<n ){
                ++i;
            }
            r=i;
            for(int j=r;j>=l;--j){
                // cout << j << " <-j num[j]-> " << num[j] << endl;
                ans[cur++]=num[j];
            }
            // cout << i << " 2\n";
        }

    }

    return ans;
}
