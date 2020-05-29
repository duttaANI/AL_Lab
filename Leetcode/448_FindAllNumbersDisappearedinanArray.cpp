class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int N = nums.size();
        vector<int> num_freq(N+1,0);
        vector<int> ans;
        for(int i=0; i<N ; ++i) {
            num_freq[nums[i]]++;
        }
        for(int i=1; i<N+1; ++i) {
            if(num_freq[i]==0) ans.push_back(i);
        }
        return ans;
    }
};