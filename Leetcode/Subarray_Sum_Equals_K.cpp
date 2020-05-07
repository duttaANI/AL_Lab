// link: https://leetcode.com/problems/subarray-sum-equals-k/solution/


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int count =0, sum =0;
        unordered_map<int, int> freq_of_sum_map;
        freq_of_sum_map.insert({ 0, 1 });
        
        for(int i=0;i<nums.size();++i)
        {
            sum += nums[i];
            count += freq_of_sum_map[sum -k];
            freq_of_sum_map[sum]++;
        }
        return count;
    }
};