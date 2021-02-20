#include <bits/stdc++.h>
#define ar array
#define ll long long
const int mxN = 1e5;



int find( int x, int p[] ){
    return x^p[x]?p[x]=find(p[x],p):x;
}

int join (int x, int y, int p[]){
    if( (x=find(x,p)) == (y=find(y,p)) )
        return 0;
    p[x] = y;
    return 1;
}

// bool join2 (int x, int y){
//     if( (x=find(x)) == (y=find(y)) )
//         return 1;
//     return 0;
// }


int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    int p[mxN];
    int n,m;

    n = A.size();
    m = B.size();
    
   
    for(int i=0; i<n; ++i){
        A[i] = A[i] - 1;
        B[i] = B[i] - 1;
    }

    iota(p,p+n,0);
    
    for( int i=0; i<C.size();++i ){
        join(A[C[i][0]-1],A[C[i][1]-1],p); // create joint sets 
    }
    
    for(int i=0;i<n;++i){
        if(A[i]!=B[i]){
            if(find(A[i],p)!=find(B[i],p)){
                return 0;
            }
        }
    }
    
    return 1;
}
