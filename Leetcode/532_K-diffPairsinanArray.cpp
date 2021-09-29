class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp; // num , freq
        
        for( int i : nums ){
            mp[i]++;
        }
        
        int pairs = 0;
        for(  auto it : mp ){
            int n = it.first;
            if(k>0){
                if( mp.find(n+k)!=mp.end() ){
                    ++pairs;
                }
            }
            else{ // k =0
                if( mp[n]>1 ){
                    ++pairs;
                }
            }  
        }
        return pairs;
    }
};