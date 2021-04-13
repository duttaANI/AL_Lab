class Solution{
  public:
    int maxLen(int arr[], int N)
    {
        // Your code here
        vector<int> arr2;
        for(int i=0;i<N;++i){
            if( arr[i]==0 )
                arr2.push_back( -1 );
            else{
                arr2.push_back(  1 );
            }
        }
        
        int k = 0;
        unordered_map<int , priority_queue< int, vector<int> , greater<int> >  >mp;
        int psum = 0,ans=0;
        mp[psum].push(-1);
        for(int i=0;i<N;++i){
            psum += arr2[i];
            if( mp.find( psum-k )!=mp.end()  ){
                int idx = mp[ psum-k ].top();
                if( i-idx > ans ){
                    ans = i-idx;
                }
            }
            mp[ psum ].push( i );
        }
        
        return ans;
    }
};
