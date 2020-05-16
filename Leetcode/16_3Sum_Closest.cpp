// Two pointer
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = nums[0] + nums[1] + nums[2];
        sort(nums.begin(),nums.end());
        int left_ptr,right_ptr,cur_sum;
        for(int i=0; i< nums.size(); ++i)
        {
            left_ptr = i+1;
            right_ptr = nums.size()-1;
            while(left_ptr<right_ptr)
            {
                cur_sum = nums[i] + nums[left_ptr] + nums[right_ptr];
                if(cur_sum > target) right_ptr--;
                else ++left_ptr;
                
                if(abs(cur_sum - target)< abs(result-target))
                    result = cur_sum;
            }
        }
        
        return result;
    }
};