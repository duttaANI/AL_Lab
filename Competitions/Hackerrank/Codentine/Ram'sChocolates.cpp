#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int maxi(vector<int>& nums) {
        
    if(nums.size()==0)
        return 0;

    if(nums.size()==1)
        return nums[0];
    if(nums.size()==2)
        return max(nums[0],nums[1]);

    vector<int> max_dp(nums.size(),0);
    max_dp[0] = nums[0];
    max_dp[1] = max(nums[0],nums[1]);

    for( int i=2;i<nums.size(); ++i)
    {
        max_dp[i] = max(nums[i]+max_dp[i-2],max_dp[i-1]);
    }

    return max_dp[nums.size()-1];
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    int T,N,C;
    cin >> T;
    vector<int> choc;
    for(int i=0; i<T;++i){
        cin >> N;
        for(int j=0; j<N; ++j){
            cin >> C;
            choc.push_back(C);
        }
        cout<< maxi(choc)<< "\n";
        choc.clear();
    }
    return 0;
}
