// Recursion with memoisation

class Solution {
public:
    int count = 0;
    int findTargetSumWays(vector<int>& nums, int S) {
        vector <vector<int>> memo (nums.size() , vector<int> (2001,INT_MIN) );
        
        return calculate(nums, 0, 0, S, memo);
    }
    
    int calculate (const vector<int>& nums, int i, int sum, int S, vector <vector<int>>& memo) {
        if (i==nums.size()) {
            if (sum == S)
                return 1;
            else
                return 0;
        }
        else
        {
            if(memo[i][sum+1000] != INT_MIN) { // to avoid repeated calls /*It can be easily observed that in the last approach, a lot of redundant function calls could be made with the same value of iii as the current index and the same value of sumsumsum as the current sum, since the same values could be obtained through multiple paths in the recursion tree.*/
                return memo[i][sum+1000];
            }
            int add = calculate(nums, i+1, sum+nums[i], S, memo);
            int sub = calculate(nums, i+1, sum-nums[i], S, memo);
            memo[i][sum+1000] = add + sub;
            return memo[i][sum+1000];
        }
    }
};



// Slowest using recursion
class Solution {
public:
    int count = 0;
    int findTargetSumWays(vector<int>& nums, int S) {
        calculate(nums, 0, 0, S);
        return count;
    }
    
    void calculate (const vector<int>& nums, int i, int sum, int S) {
        if (i==nums.size()) {
            if (sum == S)
                count++;
        }
        else
        {
            calculate(nums, i+1, sum+nums[i], S);
            calculate(nums, i+1, sum-nums[i], S);
        }
    }
};