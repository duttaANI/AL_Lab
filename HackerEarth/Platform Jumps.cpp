/*

There are N platforms in a row , each with unique height . You are given the platforms in the form of an array A of size N, where the height of the ith platform is A[i] ( i <= i <= N ).

You can perform the following operation:

If you are standing on the ith platform , you can jump on any jth platform such that the height of the ith platform is greater than the height of the jth platform .

Task

Determine the minimum number of jumps that are required to go from the tallest platform to the ith platform (for each valid i).

*/

#include <bits/stdc++.h>
using namespace std;
#define ar array

ar<int,2> expand(int idx, vector<int> A){
    int l = idx-1;
    int r = idx+1;
    
    while( l>=0 ){
        if( (int)(A[idx])>A[l] ){
            --l;
        }
        else{
            break;
        }
    }
    
    if( l<0 || l==idx ){
        l=-2;
    }
    
    while( r<(int)(A.size()) ){
        if( (int)A[idx]>A[r] ){
            ++r;
        }
        else{
            break;
        }
    }
    
    if(  r>= (int)(A.size()) || r==idx ){
        r=-2;
    }
    
    return {l,r};
}

vector<int> Min_Jumps ( int N, vector<int> A ){
    vector<int> ans(N,0);
    map< int, ar<int,2> > mp; // { i , { j,k } }
    
    map<int,int> iToA;
    map<int,int> AToi;
    
    int big = A[0];
    for( int i=0; i<N; ++i ){
        big = max({ big,A[i] });
        mp[i] = expand(i,A);
        
        iToA[i] = A[i];
        AToi[ A[i] ] = i;
    }
    
    sort(A.begin(),A.end() );
    reverse( A.begin(),A.end() );
    
    for(int i=0; i< A.size();++i){
        int m;
        if( A[i]==big ){
            int k = AToi[A[i]];
            ans[k] = 0;
            continue;
        }
        
        int k = AToi[A[i]];
        int lidx = mp[k][0];
        int ridx = mp[k][1];
        
        if( lidx>=0 && ridx<N ){
            m = min(ans[lidx],ans[ridx]) +1;
        }
        else if (  lidx<0 && ridx<N ){
            m = ans[ridx] + 1;
        }
        else if ( lidx>=0 && ridx>=N ){
            m = ans[lidx] + 1;
        }
        
        ans[k] = m;
    }
    
    return ans;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    
    for(int i_A=0;i_A<N;++i_A){
        cin >> A[i_A];
    }
    
    vector<int> out;
    out = Min_Jumps(N,A);
    for(int i=0;i<out.size();++i){
        cout << " " << out[i];
    }
    
}