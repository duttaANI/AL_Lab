#define lt 0 // less than
#define gt 1 // greater than

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return 1;
        if(n==2) {
            if( arr[0]!=arr[1] ){
                return 2;
            }
            return 1;
        }
        
        int all_equal = 1;
        for(int i=0; i+1<arr.size(); ++i){
            if( arr[i]!=arr[i+1] ){
                all_equal = 0;
                break;
            }
        }
        
        if(all_equal) return 1;
        
        
        int cmp_prev ,cmp;
        
        if( arr[1]<arr[0] ){
            cmp_prev = lt;
        }
        else if ( arr[1]>arr[0] ){
            cmp_prev = gt;
        }
        else{
            cmp_prev = -1;
        }
        
        int ans = 1,mx_ans=1;
        
        for(int i=1; i+1<n; ++i){
            
            if( arr[i+1]<arr[i] ){
                cmp = lt;
            }
            else if ( arr[i+1]>arr[i] ){
                cmp = gt;
            }
            else{
                cmp = -1;
            }
            
            // cout << cmp_prev << " " << cmp << endl;
            
            if( cmp!=-1 && cmp == !cmp_prev && cmp_prev!=-1 ){
                ++ans;
                mx_ans = max( { mx_ans,ans } );
            }else{
                ans = 1;
            }
            
            cmp_prev = cmp;
        }
        
        return mx_ans+1;
    }
};