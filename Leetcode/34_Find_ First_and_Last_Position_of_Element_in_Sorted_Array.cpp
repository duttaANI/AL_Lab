class Solution {
public:
    vector<int> expand(vector<int>& nums , vector<int>& ans, int left , int target){
        
        int right =left;
        while(left>-1           && nums[left] ==target) --left ;
        while(right<nums.size() && nums[right]==target) ++right;
        
        ans[0]=left+1;   ans[1]=right-1;
        
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> ans(2,-1); 
        if(nums.size()==0) return ans;
        
        //Bin Search
        int low = 0, high = nums.size()-1 , mid;
    
        while(low<high){
            mid = low + (high-low)/2;
            if(nums[mid]<target)  low=mid+1;
            else high = mid-1;
        }
        //cout << nums[low] << " " << high << " " << target;
        if(nums[low]==target)
            ans = expand(nums,ans,low,target);
        else if( low+1<nums.size() && nums[low+1]==target)
            ans = expand(nums,ans,low+1,target);
        
        
        return ans;
    }
};
