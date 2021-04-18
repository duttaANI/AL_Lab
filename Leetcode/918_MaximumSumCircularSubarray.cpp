class Solution {
public:
    int maxSubarraySumCircular(vector<int>& a) {
        // your code here
        int n = a.size();
        vector<int> b(n,0);
        int sum = 0;
        for(int i=0;i<n;++i){
            sum += a[i];
            b[i] = -a[i];
        }
        
        // kadane for -ve
        int cmx = b[0], gmx = b[0];
        for(int i=1;i<n;++i){
            cmx = max({ cmx+b[i] , b[i] });
            if( cmx > gmx ){
                gmx = cmx;
            }
        }
        
        // kadane for  +ve
        int cmx2 = a[0], gmx2 = a[0];
        for(int i=1;i<n;++i){
            cmx2 = max({ cmx2+a[i] , a[i] });
            if( cmx2 > gmx2 ){
                gmx2 = cmx2;
            }
        }
        
        if( sum - (-gmx) ==0  ) return gmx2;
        
        return max({ gmx2 , sum - ( -gmx )});
    }
};