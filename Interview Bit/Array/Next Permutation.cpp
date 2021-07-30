vector<int> Solution::nextPermutation(vector<int> &A) {
    int s = -1,g=-1;
    int n = A.size();
    for(int i=n-2;i>=0;--i){
        if( A[i]<A[i+1] ){
            s=i;
            break;
        }
    }
    
    if( s==-1  ){
        sort(A.begin(),A.end());
    }
    else{
        for(int i=n-1;i>s;--i){
            if( A[i]>A[s]  ){
                g=i;
                break;
            }
        }
        swap(A[s],A[g]);
        sort(A.begin()+s+1,A.end());
    }
    return A;
}