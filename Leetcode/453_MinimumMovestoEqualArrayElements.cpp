class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int mini = nums[0];
        for(int i=0;i<n;++i){
            sum += nums[i];
            mini = min(mini,nums[i]);
        }
        
        int ans = sum - n*mini;
        return ans;
    }
};