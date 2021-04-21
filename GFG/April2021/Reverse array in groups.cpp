#include<bits/stdc++.h>
class Solution{
public:
    //Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long>& arr, int n, int k){
        // code here
        int i;
        for(i=0; i+k<n; i+=k){
            reverse(arr.begin()+i,arr.begin()+i+k);
        }
        if(i!=n-k-1){
            reverse(arr.begin()+i,arr.begin()+n);
        }
    }
};