int Solution::strStr(const string A, const string B) {
    if(B.size()==0) return -1;

    int n = A.size();
    int m = B.size();
    int j ;
    for(int i=0;i<n;++i){
        j=0;
        while( i<n && j<m && A[i]==B[j]   ){
            ++i;
            ++j;
        }
        if(j==m){
            return i-j;
        }
        else{
            i = i-j;
        }
    }
    return -1;
}
