#include <iostream>
#include <bits/stdc++.h> 
#include <cstdlib>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp( m , vector<int> (n));
        
        for (int i=0; i<dp.size();++i )
            dp[i][0] = 1;
        
        for (int i=0; i<dp[0].size();++i )
            dp[0][i] = 1;
        
        for(int i=1; i<dp.size(); ++i)
        {
            for(int j=1; j<dp[0].size(); ++j)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
        
        //return fact(m+n-2)/(fact(m-1)*fact(n-1));
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        int ret = Solution().uniquePaths(m, n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}