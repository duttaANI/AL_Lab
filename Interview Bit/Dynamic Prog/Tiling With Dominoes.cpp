#include <bits/stdc++.h>
#define ll long long
const int M = 1e9 + 7,mxN = 1e5;

ll dpA[mxN+10];
ll dpB[mxN+10];

int Solution::solve(int A) {
    if(A%2==1) return 0;
    dpA[0] = 1;
    dpA[1] = 0;
    dpB[0] = 0;
    dpB[1] = 1;
    
    for(int i=2; i<=A;++i){
        dpA[i] = (dpA[i-2]%M + (2*dpB[i-1])%M)%M ;
        dpB[i] = (dpA[i-1]%M + dpB[i-2]%M)%M;
    }
    
    
    // for(int i =0; i<=A;++i){
    //     cout << dpA[i] << " "; 
    // }
    // cout << "\n";
    return dpA[A]%M;
    
    
}