// link : https://leetcode.com/problems/largest-divisible-subset/discuss/684985/C%2B%2B-clear-code-dynamic-programming-fastest-solution-100-faster-video-explanation
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        if (nums.size()==0 || nums.size()==1) return nums;
        sort(nums.begin(), nums.end());
        vector<int> dp (n,1);
        vector<int> parent (n,0);
        int countMax=1;
        int ansIndex = 0;
        for(int i=1; i<nums.size(); i++)
        {
            int val=0;
            parent[i] = i;
            for(int j=0; j<i; j++)
            {
                if( nums[i]%nums[j]==0 && val<dp[j] )
                {
                    val = dp[j];
                    parent[i] = j;
                    if(countMax < val+1)
                    {
                        countMax = val+1;
                        ansIndex = i;
                    }
                }
            }
            dp[i] = val+1;
        }
        // for(auto i:dp){
        //     cout<<i<<endl;
        // }
        for(int i=0; i< countMax; i++)
        {
            ans.push_back(nums[ansIndex]);
            ansIndex = parent[ansIndex];
        }
        return ans;
    }
};

// My failed approach
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==1 || nums.size()==0 ) return nums;
        //vector<int> ans;
        int n = nums.size();
        vector<vector<int>> dp ( n , vector<int> (0,0) );
        sort(nums.begin(),nums.end());
        
        for (int i=0 ;i<n; ++i) {
            dp[i].push_back(nums[i]);
        }
        
         for (int i=0 ;i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                if(nums[i]/nums[j]==0 && nums[j]/nums[i]==0) {
                    dp[i].push_back(nums[j]);
                }
            }
        }
        int largest_size = 1;
        if(dp[0][0]!=1)
            largest_size = 0;
        for (int i=1; i<n ;++i) {
            if(dp[i].size()>dp[largest_size].size() )
                largest_size = i;
        }
        
        if(nums[0]==1) dp[largest_size].push_back(1);
        
        return dp[largest_size];
    }
};