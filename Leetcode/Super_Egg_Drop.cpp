#include <iostream>
#include <bits/stdc++.h> 
#include <cstdlib>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    int f(int x, int K, int N)  // f(t,K) = 1+ f(t-1,K) + f(t-1,K-1) = 'ans' = for loop of function 'f'  , where 'f' => max floors we can solve in 't' tries and 'K' eggs , also solving floors means we can tell after which floor of building the eggs will start  breaking. Also here var 'x' represents var 't'.
    {
        int ans=0 , r=1;
        for(int i=1; i <= K; ++i)
        {
            r = r*(x-i+1);
            r = r/i;
            ans = ans +r;
            if( ans >= N)
                break;
        }
        return ans;
    }
    
    int superEggDrop(int K, int N) {
        int lo = 1, hi =N;
        while(lo<hi)
        {
            int mi = lo + (hi -lo)/2;
            if(  f(mi, K, N)<N  )  // if (tries i.e. 'mi') decrease => f decrease
                lo = mi+1;
            else
                hi = mi;
        }
        return lo;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int K = stringToInteger(line);
        getline(cin, line);
        int N = stringToInteger(line);
        
        int ret = Solution().superEggDrop(K, N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
