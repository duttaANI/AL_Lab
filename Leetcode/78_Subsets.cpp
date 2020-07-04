class Solution {
public:
    
    void get_SET(vector<int> &temp, vector<int> &nums, int i, int n) {
        for (int j=0; j<n && i>=0; ++j) {
            if(i & 1) temp.push_back(nums[j]);
            //cout << "i " << i <<  " " << (i & 1) << "\t";
            i=i>>1; // Right shift i by 1
        }
        //cout << "\n";
        return ;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        for (int i=0; i<pow(2, n); ++i) {
            get_SET(temp, nums, i, n);
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};
