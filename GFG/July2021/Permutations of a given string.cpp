class Solution
{
	public:
		void permute(string &s, int i, vector<string>&ans ) {
            if (i == s.size() - 1) {
                ans.push_back(s);
                return;
            }
            for (int j = i; j < s.size(); j++) {
                swap(s[i], s[j]);
                permute(s, i + 1, ans);
                swap(s[i], s[j]);
            }
            return;
        }
        vector<string>find_permutation(string S)
        {
            vector<string>ans;
            permute(S, 0, ans);
            sort(ans.begin(), ans.end());
            return ans;
        }
};