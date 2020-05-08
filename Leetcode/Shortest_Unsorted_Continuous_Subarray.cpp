class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        
        int end = nums.size();
        int mini = 2147483647;
        int maxi = -2147483648;
        
        for(int i=1; i<end;++i)
        {
            if(nums[i]<nums[i-1])
                mini = min(mini,nums[i]);
        }
        
        for(int i=end-2; i>=0; i--)
        {
            if(nums[i]>nums[i+1])
                maxi = max(maxi,nums[i]);
        }
        
        int l,r;
        
        for(l=0; l<end; ++l)
        {
            if(mini<nums[l])
                break;
        }
        
        for(r = end-1; r>=0; r--)
        {
            if(maxi>nums[r])
                break;
        }
        
        return r-l<0 ? 0 : r-l+1;
        
    }
};