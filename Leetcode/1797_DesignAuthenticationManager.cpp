class AuthenticationManager {
public:
    int TTL;
    unordered_map<string,int> mp; // token name , expiry time
    AuthenticationManager(int timeToLive) {
        TTL = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime + TTL;
    }
    
    void renew(string tokenId, int currentTime) {
        if( mp.find(tokenId)!=mp.end() && mp[tokenId]>currentTime ){
            mp[tokenId] = TTL + currentTime;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int res = 0;
        for(auto it : mp){
            if( it.second  > currentTime  ){
                ++res;
            }
        }
        return res;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */