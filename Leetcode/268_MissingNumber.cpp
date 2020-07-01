class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i=0; i<nums.size(); ++i)
            sum += nums[i];
        
        return (n+1)*(n)/2 - sum;
    }
};