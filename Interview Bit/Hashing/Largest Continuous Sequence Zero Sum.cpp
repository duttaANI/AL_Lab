#include<bits/stdc++.h>
#define ar array

vector<int> Solution::lszero(vector<int> &A) {
    // Complete the function
    int ans[3] = {0,0,0};
    int K = 0;
    unordered_map< int , priority_queue< int , vector<int> , greater<int> > >mp;
    int psum = 0;
    mp[psum].push(-1);
    int N = A.size();
    for( int i=0; i<N; ++i ){
        psum += A[i];
        if( mp.find( psum-K )!=mp.end() ){
            int idx = mp[ (psum-K) ].top();
            if( i-idx > ans[0] ){
                ans[0] = (i-idx);
                ans[1] = idx;
                ans[2] = i;
            }
        }
        mp[ psum ].push(i);
    }
    
    // cout << ans[0] << "  ans[0] " << endl;
    
    vector<int> res;
    for(int i=ans[1]+1 ; i<=ans[2]; ++i){
        res.push_back(A[i]);
    }
    
    return res;
}