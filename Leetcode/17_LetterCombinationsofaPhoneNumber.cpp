// link : https://leetcode.com/problems/letter-combinations-of-a-phone-number/discuss/8167/C%2B%2B-Clean-Code-5-Solutions
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return vector<string>();
        }
        vector<string> words{ "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        deque<string> q;
        q.push_back("");
        
        for ( char digit : digits ){
            int d = digit - '0';
            for (int i = q.size(); i > 0; i--) {
                string token = q.front();
                
                q.pop_front();
                for (char ch : words[d]) {
                    q.push_back(token + ch);
                }
            }
        }
        
        return vector<string>(q.begin(), q.end());
    }
};