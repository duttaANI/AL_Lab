class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] == target )
                return i;
            else if ( i-1>=0 && target < nums[i] && target >nums[i-1])
                return i;
        }
        if (target < nums[0]) return 0;
        else
            return nums.size();
    }
};