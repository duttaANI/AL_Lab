#include <bits/stdc++.h>
int Solution::largestRectangleArea(vector<int> &A) {
    
    set<int> s; // for avoiding duplicates in heights
   for(auto x:A)s.insert(x);
    int area=0;
    for(auto x:s){
        int count=0;
        for(auto i:A){
            if(i<x)count=0;
            else {count++;
              area=max(x*count,area);
            }
        }
    }
    return area;
}