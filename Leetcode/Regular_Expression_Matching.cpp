#include <iostream>
#include <bits/stdc++.h> 
#include <cstdlib>
#include <queue>
using namespace std; 

class Solution {
public:
    
    bool recursive(string s,string p)
    {
        int var1=(s.length()>0)?1:0;    int var2=(p.length()>0)?1:0;
        if(!var2)
            return !var1;
        
        int first_match = var1 && (p[0]=='.' || p[0]==s[0]);  // ( || ) - If EITHER or BOTH sides of the operator is true, the result will be true.
        
        if( p.length()>=2 && p[1]=='*'  )
            return recursive(s,p.substr(2,p.length())) || (  first_match && recursive(s.substr(1,s.length()),p)  );
        else
            return first_match && recursive(s.substr(1,s.length()),p.substr(1,p.length()));
        
    }
    
    bool isMatch(string s, string p) {
        return recursive(s,p);
        
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
        getline(cin, line);
        string p = stringToString(line);
        
        bool ret = Solution().isMatch(s, p);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}