#define ar array
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue < ar<int,2> , vector< ar<int,2 >   > > pq;
        int n = piles.size();
        int tot = 0;
        int rem = 0;
        
        for( int i=0;i<n;++i  ){
            pq.push({ piles[i],i });
            tot += piles[i];
        }
        
        while( k  ){
            ar<int,2> f = pq.top(); pq.pop();
            if( f[0]==0 ){
                return (tot-rem);
            }
            rem += f[0]/2;
            // cout << f[0]/2 << "  <-pq.top[0]  rem-> " << rem << "  k-> " << k << endl;
            pq.push({ f[0]-f[0]/2, f[1]  });
            --k;
        }
        
        return (tot-rem);
    }
};