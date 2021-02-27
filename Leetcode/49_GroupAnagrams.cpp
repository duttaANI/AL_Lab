class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        set<string> ss;
        int n = strs.size();
        for(int i=0; i<n; ++i){
            string dup = strs[i];
            sort(dup.begin(),dup.end());
            mp[dup].push_back(strs[i]);
            ss.insert(dup);
        }
        vector<vector<string>> ans;
        for(auto v : ss){
            ans.push_back(mp[v]);
        }
        return ans;
    }
};