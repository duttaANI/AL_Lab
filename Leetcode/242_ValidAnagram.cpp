class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
        
        vector<int> table (26,0);
        
        for (int i=0; i<s.length(); ++i) {
            table[s[i]-'a']++;
        }
        
        for (int i=0; i<t.length(); ++i) {
            table[t[i]-'a']--;
            if(table[t[i]-'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};