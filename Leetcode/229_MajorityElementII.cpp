class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> freq_map;
        
        for (auto & i : nums) {
            freq_map[i]++;
        }
        
        for (auto it: freq_map) {
            if (it.second > nums.size()/3) {
                ans.push_back(it.first);
            }
        }
        
        return ans;
    }
};
