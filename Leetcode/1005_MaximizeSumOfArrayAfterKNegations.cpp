class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        
        sort(A.begin(),A.end());
        
        int n = A.size();
        int sum=0;
        int i;
        
        for (i=0; i<n ; ++i) {
            if(A[i]<0 && K>0){
                sum += -A[i];
                --K;
                A[i]= -A[i];
            } else if ( K==0 ){
                sum += A[i];
            }else {
                break;
            }
        }
        
        while( i<n ){
            sum += A[i];
            ++i;
        }
        
        sort(A.begin(),A.end());
        
        if(K%2!=0 && K>0) 
            sum += 2*-A[0];
        
        return sum;
    }
};