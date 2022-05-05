class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int ans = INT_MAX;
        unordered_map <int,int> mp;
        int n = cards.size();
        for(int i=0;i<n;++i){
            if( mp.find(cards[i])!=mp.end() ){
                int cur = i - mp[cards[i]];
                ans = min(ans,cur);
            }
            mp[cards[i]] = i;
        }
        if(ans==INT_MAX) return -1;
        return ans+1;
    }
};