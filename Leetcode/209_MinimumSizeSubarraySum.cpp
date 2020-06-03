


///////////////////////////////
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(); int ans = n+1;
        int left = 0; int sum = 0;
        for (int i=0; i<n; i++) {
            sum = sum + nums[i];
            while(sum>=s) {
                ans = min(ans,i+1-left);
                sum = sum - nums[left++];
            }
        }
        return (ans!=n+1)?ans:0;
    }
};