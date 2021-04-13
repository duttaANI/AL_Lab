
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int ans=0;
        unordered_map< int , priority_queue< int , vector<int> , greater<int> > >mp;
        int psum = 0;
        mp[psum].push(-1);
        for( int i=0; i<N; ++i ){
            psum += A[i];
            if( mp.find( psum-K )!=mp.end() ){
                int idx = mp[ (psum-K) ].top();
                if( i-idx > ans ){
                    ans = (i-idx);
                }
            }
            mp[ psum ].push(i);
        }
        
        return ans;
    } 

};