#include <bits/stdc++.h>

int distinctSubKOdds(vector<int> arr, int n, int k)
{
	// Write your code here
    int ans = 0; 
    unordered_set<string> hset;
    
    for(int i=0;i<n;++i){
        string subarr = "";
        int oddcnt = 0;
        
        for(int j=i;j<n;++j){
            if(  arr[j]%2==1  ){
                ++oddcnt;
            }
            if( oddcnt > k  ){
                break;
            }
            
            string ele = to_string(arr[j]);
            for( char c: ele )
            	subarr.push_back( c );
            subarr.push_back(' ');
            
            if(  hset.find(subarr)==hset.end() ){
                hset.insert(subarr);
                ++ans;
            }
        }
    }
    
    return ans;
}