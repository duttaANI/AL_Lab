// link : https://leetcode.com/problems/isomorphic-strings/discuss/57796/My-6-lines-solution
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};

// My failed approach

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,char> join;
        for(int i=0; i<s.length(); ++i){
            if(join.count(s[i]) && join[s[i]]==t[i] && join[t[i]]==s[i]){
                continue;
            }else if(!join.count(s[i]) ){
                if(!join.count(t[i]))
                    join[s[i]] = t[i];
                else
                    return false;
            }else if(join.count(s[i]) && join[s[i]]!=t[i] ) {
                return false;
            }
        }
        
        for (auto it: join) {
            std::cout << it.first << " - " << it.second <<  '\n';
        }
        return true;
    }
};