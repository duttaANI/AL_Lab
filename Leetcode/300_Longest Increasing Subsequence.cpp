// BRUTE FORCE TLE

class Solution {
public:
    
    int LIS(vector<int>& nums,int prev, int curpos){
        if(curpos == nums.size() ){
            return 0;
        }
        int taken = 0;
        if( nums[curpos]>prev ){
            taken = 1+LIS(nums,nums[curpos],curpos+1);
        }
        int nottaken = LIS(nums,prev,curpos+1);
        
        return max({taken,nottaken});
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        return LIS(nums,INT_MIN,0);
        
    }
};

// O(n^2)

class Solution {
public:
    
    int dp[2501][2500];
    
    int LIS(vector<int>& nums,int prevIDX, int curpos){
        if(curpos == nums.size() ){
            return 0;
        }
        if (dp[prevIDX + 1][curpos] >= 0) {
            return dp[prevIDX + 1][curpos];
        }
        int taken = 0;
        if( prevIDX <0 || nums[curpos]> nums[prevIDX] ){
            taken = 1+LIS(nums,curpos,curpos+1);
        }
        int nottaken = LIS(nums,prevIDX,curpos+1);
        
        dp[prevIDX+1][curpos] =  max({taken,nottaken});
        
        return dp[prevIDX+1][curpos];
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        memset(dp,-1,sizeof(dp));
        return LIS(nums,-1,0);
        
    }
};



// faster 

class Solution {
public:
    
    int dp[2501];
    
    
    int lengthOfLIS(vector<int>& nums) {
        
        if(nums.size()==0) return 0;
        dp[0] = 1;
        int maxans = 1;
        for(int i=0; i<nums.size(); i++){
            int maxval = 0;
            for(int j=0; j<i; ++j){
                if(nums[i]>nums[j]){
                    maxval = max(maxval,dp[j]);
                }
            }
            dp[i] = maxval + 1;
            maxans = max(maxans,dp[i]);
        }
        return maxans;
    }
};

// O (nlog(n))

class Solution {
public:
    
    
    int lengthOfLIS(vector<int>& nums) {
     vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
            if(it==res.end()) res.push_back(nums[i]);
            else *it = nums[i];
        }
        return res.size();
    }
};