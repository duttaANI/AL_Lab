// Not my code
// link : https://leetcode.com/problems/remove-invalid-parentheses/discuss/75050/My-C%2B%2B-DFS-Solution-16ms
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> result;
        int left_removed = 0;
        int right_removed = 0;
        for(auto c : s) {
            if(c == '(') {
                ++left_removed;
            }
            if(c == ')') {
                if(left_removed != 0) {
                    --left_removed;
                }
                else {
                    ++right_removed;
                }
            }
        }
        helper(s, 0, left_removed, right_removed, 0, "", result);
        return vector<string>(result.begin(), result.end());
    }
private:
    void helper(string s, int index, int left_removed, int right_removed, int pair, string path, unordered_set<string>& result) {
        if(index == s.size()) {
            if(left_removed == 0 && right_removed == 0 && pair == 0) {
                result.insert(path);
            }
            return;
        }
        if(s[index] != '(' && s[index] != ')') {
            helper(s, index + 1, left_removed, right_removed, pair, path + s[index], result);
        }
        else {
            if(s[index] == '(') {
                if(left_removed > 0) {
                    helper(s, index + 1, left_removed - 1, right_removed, pair, path, result);
                }
                helper(s, index + 1, left_removed, right_removed, pair + 1, path + s[index], result);
            }
            if(s[index] == ')') {
                if(right_removed > 0) {
                    helper(s, index + 1, left_removed, right_removed - 1, pair, path, result);
                }
                if(pair > 0) {
                    helper(s, index + 1, left_removed, right_removed, pair - 1, path + s[index], result);
                }
            }
        }
    }
};


// my failed code

class Solution {
public:
    
    void add_char(vector<string>& ans, string s,string  str, int op_b, int cl_b, int i, int diff) {
        if( (op_b>=0 && cl_b>=0) && i<s.length() ) // base case
        {
            if(s[i]=='(')
            {
                add_char(ans, s, str += s[i], op_b-1, cl_b, i+1, diff);
                add_char(ans, s, str        , op_b-1, cl_b, i+1, diff);
            }
            else if (s[i]==')')
            {
                add_char(ans, s, str += s[i], op_b, cl_b-1, i+1, diff);
                add_char(ans, s, str        , op_b, cl_b-1, i+1, diff);
            }
            else
            {
                add_char(ans, s, str += s[i], op_b, cl_b  , i+1, diff);
            }
        }
        else {
            if( abs(op_b-cl_b)==diff   && (op_b==0 || cl_b==0) )
                ans.push_back(str);
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> ans;
        string str = "";
        int op_b=0, cl_b=0;
        for (int i=0; i<s.length(); ++i){
            if(s[i]=='(') 
                op_b++;
            else
                cl_b++;
        }
        
        add_char(ans, s, str, op_b, cl_b, 0, abs(op_b-cl_b) );
        
        return vector<string>(ans.begin(), ans.end());
    }
};