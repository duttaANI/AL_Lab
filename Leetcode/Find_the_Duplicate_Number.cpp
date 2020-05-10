class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int hare = 0;
        int tortoise = 0;
        
        do
        {
            hare = nums[nums[hare]];
            tortoise = nums[tortoise];
        }while(hare!=tortoise);
        
        tortoise = 0;
        while(hare!=tortoise)
        {
            hare = nums[hare];
            tortoise = nums[tortoise];
        }
        
        return hare;
    }
};