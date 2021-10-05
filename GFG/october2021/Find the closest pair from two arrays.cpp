class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
        sort( arr, arr+n );
        sort( brr, brr+m );
        
        int res_l=0 ,  res_r=m-1 , l=0 ,r=m-1;
        int diff = abs( arr[l] + brr[r] - x );
        
        while(  l<n && r>=0 ){
            if(  abs( arr[l] + brr[r] - x ) < diff ){
                res_l = l;
                res_r = r;
                diff = abs( arr[l] + brr[r] - x );
            }
            if( arr[l]+brr[r] > x ){
                --r;
            }
            else{
                ++l;
            }
        }
        return {arr[res_l],brr[res_r]};
    }
};