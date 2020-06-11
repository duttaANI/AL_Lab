// link :https://leetcode.com/problems/max-consecutive-ones/discuss/464071/Easy-to-understand-yet-fast-c%2B%2B-solution-100-memory-and-speed
class Solution {
public:
int findMaxConsecutiveOnes(vector<int>& nums) {
	int max = 0, i = 0;
	while (i < nums.size())
	{
		while (i < nums.size() && nums[i] == 0)i++;
		int subMax = 0;
		while (i < nums.size() && nums[i] == 1)
		{
			subMax++;
			i++;
		}
		if (subMax > max) max = subMax;
	}
	return max;
}
};

// My slow
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int j=0; int max_j=0;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i]==1) {
                ++j;
            }
            else {
                j=0;
            }
            max_j = max(max_j,j);
        }
        return max_j;
    }
};
