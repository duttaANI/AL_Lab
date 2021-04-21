class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        // Code here
        vector<int> l (n,0);
        vector<int> r (n,0);
        int maxl = arr[0];
        int maxr = arr[n-1];
        
        for(int i=0;i<n;++i){
            if( arr[i]>maxl ){
                maxl = arr[i];
            }
            l[i] = maxl;
        }
        
        for(int i=n-1;i>=0;--i){
            if( arr[i]>maxr){
                maxr = arr[i];
            }
            r[i] = maxr;
        }
        
        int ans = 0;
        
        for(int i=0;i<n;++i){
            ans += max( {  min(r[i],l[i]) - arr[i],0   } );
        }
        
        
        return ans;
    }
};