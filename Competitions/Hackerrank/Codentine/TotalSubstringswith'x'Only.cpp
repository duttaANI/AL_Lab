#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    cin >> s;
    vector<int> dp;
    int slow=0, fast=0;
    unsigned i=0;
    while( i<s.length()  ){
        while(s[i]=='x') {
            ++fast;
            ++i;
        }
        dp.push_back(fast-slow);
        while(s[i]=='y') {
            ++fast;
            ++i;
        }
        slow =fast;
    }
    //cout << "size" << dp.size() << "\n";
    int totSub=0;
    unsigned a;
    for( a=0; a<dp.size(); ++a){
        //cout << a << " ";
        totSub += (dp[a])*(dp[a]+1)/2;
    } 
    cout << totSub;
    
    return 0;
}
