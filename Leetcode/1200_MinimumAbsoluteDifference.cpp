class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int minAbsDiff = INT_MAX;
        for (int i=1; i<n; ++i) {
            minAbsDiff = min(arr[i]-arr[i-1],minAbsDiff);
        }
        for (int i=1; i<n; ++i) {
            if(arr[i]-arr[i-1] == minAbsDiff) {
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        
        return ans;
    }
};