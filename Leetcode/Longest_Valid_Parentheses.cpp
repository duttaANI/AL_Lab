#include <iostream>
#include <bits/stdc++.h> 
#include <cstdlib>
#include <queue>
#include <string>
using namespace std; 


class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.length(),0);

        int maxans =0;
        int edge_handle1=0;
        for (int i = 1; i < s.length(); ++i)
        {
            if(s[i]==')' )
            {
                if(s[i-1]=='(')
                {
                    edge_handle1 = (i-2)>=0 ? dp[i-2]:0;
                    dp.at(i)=(edge_handle1+2);
                }
                else if ( (i - dp[i - 1])>0 && s[i-dp[i-1]-1]=='(' )
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
            }

            if(dp[i]>=maxans)
            {
                //cout << "dp[i] " << dp[i] << "\n";
                maxans=dp[i];
            }
        }

        return maxans;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().longestValidParentheses(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}