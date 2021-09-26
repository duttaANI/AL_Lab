#define ar array
#include <bits/stdc++.h>
class DetectSquares {
public:
    
    
    
    DetectSquares() {
        
    }
    
    map<ar<int,2>,int> mp;
    
    void add(vector<int> point) {
        mp[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        int cnt =0;
        for(  auto p : mp){
            ar<int,2> f = p.first;
            if( (f[0]!=point[0]) && (f[1]!=point[1]) && abs(f[0]-point[0])==abs(f[1]-point[1])  ){
                int c1 = mp[{f[0],f[1]}];
                int c2 = mp[{f[0],point[1]}];
                int c3 = mp[{point[0],f[1]}];
                cnt += c1*c2*c3;
            }
        }
        return cnt;
    }
};