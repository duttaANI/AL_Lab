// link : https://www.techiedelight.com/longest-palindromic-substring-non-dp-space-optimized-solution/
// 
#include <iostream>
#include <bits/stdc++.h> 
#include <cstdlib>
#include <queue>
#include <string>
using namespace std; 


class Solution {
public:
    string expand(string str, int low, int high)
    {
        int len = str.length();
        while(low>=0 && high<len && str[low]==str[high])
        {
            --low;    ++high;
        }
        return str.substr(low+1,high-low-1); 
    }
    
    string longestPalindrome(string s) {
        if(s.length()==0 || s.length()==1)
        {
            return s;
        }
        
        // max_str stores the maximum length palindromic substring
	    // found so far
    
	    string max_str = "", cur_str;
        
        int max_len=0,cur_len,i;
        
        for( i=0; i < s.length() - 1 ; ++i)
        {
            //------------For odd length
            cur_str = expand(s,i,i);
            cur_len = cur_str.length();
            
            if(cur_len > max_len)
            {
                max_len = cur_len;
                max_str = cur_str;
            }
            
            //------------For even length
            cur_str = expand(s,i,i+1);
            cur_len = cur_str.length();
            
            if(cur_len > max_len)
            {
                max_len = cur_len;
                max_str = cur_str;
            }
            
        }
        
        return max_str;
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
        
        string ret = Solution().longestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}