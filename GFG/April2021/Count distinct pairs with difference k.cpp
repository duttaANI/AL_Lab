#include <bits/stdc++.h>
#define ar array
class Solution{
	public:
	
	
	int TotalPairs(vector<int>nums, int k){
	    // Code here
	    sort(nums.begin(),nums.end());
	    set<ar<int,2>> s;
	    int i=0,j=0;
	    while( j<nums.size() ){
	        if( nums[j]-nums[i]<k ){
	            ++j;
	        }
	        else if ( nums[j]-nums[i]>k ){
	            ++i;
	        }
	        else{
	            if(j!=i){
	                s.insert({nums[i],nums[j]});
	                ++i;
	                ++j;
	            }else{
	                ++j;
	            }
	        }
	    }
	    return s.size();
	}

};