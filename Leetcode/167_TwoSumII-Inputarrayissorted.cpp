class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int high = numbers.size() - 1; 
        int low =0;
        int sum;
        while(low<high) {
            sum = numbers[low] + numbers[high];
            if (sum == target) {
                ans.push_back(low+1);
                ans.push_back(high+1);
                break;
            }
            else if (sum > target) 
                --high;
            else
                ++low;
        }
        
        return ans;
    }
};
