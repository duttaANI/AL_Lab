class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;++i){
            mp[nums[i]]++;
        }
        
        for(auto it: mp){
            if( it.second==1 && mp[it.first-1]==0 && mp[it.first+1]==0 ){
                ans.push_back(it.first);
            }
        }
        
        return ans;
    }
};