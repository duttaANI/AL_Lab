class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        vector<int> res;
        unordered_map<int,int> mp;
        int distinct = 0;
        for(int i=0;i<n;++i){
            
            //ignore first k elements
            if( i>=k  ){
                mp[A[i-k]]--;
                if(mp[A[i-k]]==0){
                    --distinct;
                }
            }
            mp[A[i]]++;
            if(mp[A[i]]==1){
                ++distinct;
            }
            if(i>=k-1)
            res.push_back(distinct);
        }
        
        return res;
    }
};