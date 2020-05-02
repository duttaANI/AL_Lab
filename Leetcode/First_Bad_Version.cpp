// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

#include <iostream>
#include <bits/stdc++.h> 
#include <cstdlib>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    int firstBadVersion(int n) {
       
        if(n==1)
            return 1;
        if(isBadVersion(n) && !isBadVersion(n-1))
           return n;
        
        
        
        int start = 1, end =n,mid;
        bool api_val=0;
        
        while(start<end)
        {
            mid =start + (-start+end)/2 ;
            
            api_val = isBadVersion(mid);
            
            (api_val)? (end = mid):(start = mid+1);
            
        }
        
        return start;
       
        
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        getline(cin, line);
        int bad = stringToInteger(line);
        
        int ret = Solution().firstBadVersion(n, bad);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}