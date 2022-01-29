class Solution {
public:
    int countElements(vector<int>& nums) {
        int ans = 0;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;++i){
            if( nums[i]<mini ){
                mini = nums[i];
            }
            if( nums[i]>maxi ){
                maxi = nums[i];
            }
        }
        
        for(int i=0;i<n;++i){
            if( nums[i]>mini && nums[i]<maxi ){
                ++ans;
            }
        }
        
        return ans;
    }
};