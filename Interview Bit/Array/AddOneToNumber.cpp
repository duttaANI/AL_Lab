
#include <bits/stdc++.h>
#define ll long long
vector<int> Solution::plusOne(vector<int> &A) {
    vector<int> ans;
    int carry =1;
    int dig =0;
    reverse(A.begin(),A.end());
    int j=A.size();
    while(A[j-1]==0 && A.size()!=1){
        A.pop_back();
        --j;
    }
    
    for( int i=0; i<A.size() ;++i ){
        dig = A[i]+carry;
        A[i] = dig%10;
        dig/=10;
        carry = dig ;
    }
    if(carry){
        A.push_back(carry);
    }
    reverse(A.begin(),A.end());
    return A;
}
