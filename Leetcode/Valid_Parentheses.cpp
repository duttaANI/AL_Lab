#include <iostream>
#include <bits/stdc++.h> 
#include <cstdlib>
#include <queue>
#include <string>
using namespace std; 


class Solution {
public:
    bool isValid(string s) {
        stack <char> stk; 
        int count=0;
        int flag=1;
        for (int i = 0; i < s.length(); ++i)
        {
            ++count;
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                stk.push(s[i]);
                
            }
            else if(!stk.empty())
            {
                if(  (s[i]==')' && stk.top()=='(') || (s[i]=='}' && stk.top()=='{') || (s[i]==']' && stk.top()=='[') )
                {
                    stk.pop();
                }
                else
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag && stk.empty() && (count%2==0))
            return true;
        else
            return false;

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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        bool ret = Solution().isValid(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}

/*
sample i/o:
"()"
True
"{{{[[]]}}}"
True
"{}[]{()}"
True
"{}[[)]"
False


*/


/*
        int flag=1,count1=0,count2=0,count3=0;
        for(int i=0; i<s.length();i++)
        {
            if     (s[i]=='(')
                ++count1 ;
            else if(s[i]=='{')
                ++count2 ;
            else if(s[i]=='[')
                ++count3;
            else if(s[i]==')')
                --count1;
            else if(s[i]=='}')
                --count2;
            else if(s[i]==']')
                --count3;
            
            if(count1<0 || count2<0 || count3<0) 
            {
                flag=0;
                break;
            }
        }
        
        if(flag && count1==0 && count2==0 && count3==0)
            return true;
        else
            return false;*/
