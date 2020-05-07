// link: https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size()==0)
            return 0;
        
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        
        vector<int> loot_max_dp(nums.size(),0);
        loot_max_dp[0] = nums[0];
        loot_max_dp[1] = max(nums[0],nums[1]);
        
        for( int i=2;i<nums.size(); ++i)
        {
            loot_max_dp[i] = max(nums[i]+loot_max_dp[i-2],loot_max_dp[i-1]);
        }
        
        return loot_max_dp[nums.size()-1];
    }
};