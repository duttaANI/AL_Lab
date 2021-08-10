class Solution {
    char toggleCase(char c){
        if(c>=65 && c<=90)
         c+=32;
        else if(c>=97 && c<=122)
         c-=32;
        return c;
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        int n = s.size();
        ans.push_back(s);
        for(int i = 0; i < n; i++){
            if(isalpha(s[i])){
                int n1 = ans.size();
                for(int j = 0; j < n1; j++){
                    string s1 = ans[j];
                    s1[i] = toggleCase(s1[i]);
                    ans.push_back(s1);
                }
            }
        }
        return ans;
    }
};