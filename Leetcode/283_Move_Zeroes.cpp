class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        //move non zero elements in advance
        for(int i=0; i<nums.size(); ++i)
        {
            if(nums[i]!=0)
            {
                nums[j++] = nums[i]; // Post increment!!
            }
        }
        
        for(;j<nums.size();++j)
        {
            nums[j] =0;
        }
    }
};