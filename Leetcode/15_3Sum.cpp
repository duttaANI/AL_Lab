class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<int> ans(3,0);
        vector<vector<int>> result;
        
        if(nums.size()<3)
            return result;
        
        for(int i=0; i<nums.size()-2; ++i)
        {
            if( i==0 || ( i>0 && nums[i]!=nums[i-1] ) )
            {
                int low = i+1;
                int high = nums.size()-1;
                int sum = 0 -nums[i];
                
                
                while(low<high)
                {
                    if(nums[low] + nums[high] == sum)
                    {
                        ans[0] = nums[low]; ans[1] = nums[high]; ans[2] = nums[i];
                        result.push_back(ans);
                        
                        // for duplicates
                        while(low<high && nums[low]==nums[low+1]) ++low;
                        while(low<high && nums[high]==nums[high-1]) --high;
                        ++low; --high; // Since none of "low" or "high" should be duplicate as "sum" is fixed
                    }
                    else if(nums[low]+nums[high]>sum)
                    {
                        --high;
                    }
                    else
                    {
                        ++low;
                    }
                }
            }
        }
        
        return result;
    }
};