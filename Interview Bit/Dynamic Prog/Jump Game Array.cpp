int Solution::canJump(vector<int> &nums) {
    int lastPos = nums.size()-1;
    for(int i=lastPos;i>=0;i--)
    {
        if(nums[i] >= lastPos-i )
        {
            lastPos = i;
        }
    }
    return (lastPos==0);
}