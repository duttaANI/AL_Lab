int Solution::majorityElement(const vector<int> &A) {
    int n = A.size();
    int maj_i=0, count = 1;
    for(int i=1;i<n;++i){
        if( A[maj_i]==A[i] ){
            ++count;
        }
        else{
            --count;
        }
        if( count ==0 ){
            maj_i = i;
            count = 1;
        }
    }
    // if(  2*count >= n )
    return A[maj_i];
    // return -1;
}
