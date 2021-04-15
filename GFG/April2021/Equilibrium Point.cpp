#include<bits/stdc++.h>
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        
        if(n==1){
            return 1;
        }
    
        // Your code here
        vector<long long int > psum(n+1,0);
        int sum = 0;
        for( int i=1; i<=n; ++i ){
            sum += a[i-1];
            psum[i] = sum;
        }
        
        int l=0; int r=n;
        while( l<r ){
            int mid = l + (r-l)/2;
            if( psum[mid-1] == sum - psum[mid]  ){
                return mid;
            }
            else if ( sum - psum[mid] - psum[mid-1] < 0 ){
                r = mid - 1 ;
            }
            else if ( sum - psum[mid] - psum[mid-1] > 0 ){
                l = mid + 1;
            }
        }
        
        return -1; // since my vector is n+1
        
    }

};