class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        int n = nums.size();
        int tot_pivots=0;
        for(int i=0;i<n;++i){
            if(nums[i]<pivot){
                ans.push_back(nums[i]);
            }
            else if(nums[i]==pivot){
                ++tot_pivots;
            }
        }
        
        while(tot_pivots--)
            ans.push_back(pivot);
        
        for(int i=0;i<n;++i){
            if(nums[i]>pivot){
                ans.push_back(nums[i]);
            }
        }
        
        return ans;
    }
};