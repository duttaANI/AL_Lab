// link : https://leetcode.com/problems/group-anagrams/discuss/19200/C%2B%2B-unordered_map-and-counting-sort
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        string t;
        for(string s : strs){
            t=s;
            sort(t.begin(),t.end());
            mp[t].push_back(s);
        }
        for(auto m : mp){
            ans.push_back(m.second);
        }
        return ans;
    }
};