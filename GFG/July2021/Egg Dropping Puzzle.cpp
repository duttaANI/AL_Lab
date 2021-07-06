#include <bits/stdc++.h>
using namespace std;

 
static const int  MX = 1000;
vector<vector<int>> memo( MX, vector<int> (MX, -1));

class Solution
{
    public:
    
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    
    
    int solve(int n,int k){
        if(memo[n][k]!=-1) return memo[n][k];
        
        if( k==0 || k==1  ) {
            return k;
        }
        
        
        if( n==1 ) return k;
        
        int min = INT_MAX, x, res;
        
        for (x = 1; x <= k; x++) {
            res = max(
            solve(n - 1, x - 1),
            solve(n, k - x));
            if (res < min)
                min = res;
        }
         
        memo[n][k] = min+1;
        return min + 1;
        
    }
    
    int eggDrop(int n, int k) 
    {
        // your code here
        
        return solve(n,k);
    }
};