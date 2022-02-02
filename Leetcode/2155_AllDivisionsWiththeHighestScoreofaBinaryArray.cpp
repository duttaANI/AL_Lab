class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        vector<int> pre(n+1,0),suf(n+1,0);
        
        int z = 0;
        
        for(int i=0;i<n;++i){
            // pre[i] = z;
            if(nums[i]==0){
                ++z;
            }
            pre[i+1] = z;
        }
        
        int o = 0;
        
        for(int i=n-1; i>=0; --i){
            if(nums[i]==1){
                ++o;
            }
            suf[i] = o;
        }
        
        int mx = 0;
        for(int i=0;i<=n;++i){
            mx = max({mx, pre[i]+suf[i]});
        }
        
        for(int i=0;i<=n;++i){
            if( (pre[i]+suf[i])==mx ){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};