// refer link :https://www.youtube.com/watch?v=YDf982Lb84o
#include <iostream>
#include <bits/stdc++.h> 
#include <cstdlib>
#include <queue>
#include <string>
using namespace std; 

class Solution {
public:
    int numTrees(int n) {
        vector<int> T(n+1,0) ;
        T[0]=1;
        T[1]=1;
        
        for(int i=2; i<=n;++i)
        {
            for(int j=0; j<i; ++j)
            {
                T[i] += T[j]*T[i-j-1];
            }
        }
        
        // for(int i=0; i<T.size();++i)
        //     cout << " " << T[i];

        return T[n];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().numTrees(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
