class Solution {
public:
    
    static bool cmp ( vector<int> a,  vector<int> b) {  // sort in order of left point of each interval
        return a[0] < b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end(),cmp);
        
        vector<vector<int>> ans;
        
        for (auto v : intervals) {
            if (!ans.empty() && ans[ans.size()-1][1] >= v[0]) {
                ans[ans.size()-1][1] = max(ans[ans.size()-1][1],v[1]);
            }
            else {
                ans.push_back(v);
            }
        }
        return ans;
    }
};