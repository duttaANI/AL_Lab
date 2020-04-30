#include <iostream>
#include <bits/stdc++.h> 
#include <cstdlib>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        
        vector <int> dp(n,0);
        
        dp[0] = 1;
        dp[1] = 2;
        
        for(int i=2; i< dp.size(); ++i)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n-1];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().climbStairs(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}