// link : https://www.youtube.com/watch?v=7wT5sFELf7Q
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq_map;
        unordered_map<int, int> first_seen;
        int n = nums.size();
        int min_length = 0;
        int degree = 0;
        for (int i=0; i<n; ++i ) {
            if (first_seen.count(nums[i]) == 0 )
                first_seen[nums[i]] = i;
            freq_map[nums[i]]++;
            if ( freq_map[nums[i]] > degree) {
                degree =  freq_map[nums[i]];
                min_length = i - first_seen[nums[i]] + 1;
            }else if ( freq_map[nums[i]] == degree ) {
                min_length=   min (min_length, i - first_seen[nums[i]] + 1);
            }
        }
       
        return min_length;
    }
};