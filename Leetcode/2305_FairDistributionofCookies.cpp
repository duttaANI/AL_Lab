class Solution {
public:
    vector<int> cookies;
    vector<int> sumv;
    int k;
    
    int distributeCookies(vector<int>& cookies, int k) {
        this->cookies = cookies;
        this->sumv = vector<int>(k, 0);
        this->k = k;
        
        sort(cookies.begin(), cookies.end(), greater<>());
        int left = *max_element(cookies.begin(), cookies.end());
        int right = accumulate(cookies.begin(), cookies.end(), 0);
        
        while (left < right) {
            int mid = (left + right) >> 1;
            sumv = vector<int>(k, 0);
            if (solve(0, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
    bool solve(int start, int cap) {
        if (start == cookies.size()) return true;
        
        for (int i = 0; i < k; i++) {
            if (sumv[i] + cookies[start] > cap) continue;
            sumv[i] += cookies[start];
            if (solve(start + 1, cap)) return true;
            sumv[i] -= cookies[start];
            if (sumv[i] == 0) break;
            
        }
        
        return false;
    }
};

// BELOW backtrack is TLE
class Solution {
public:
    int ans = INT_MAX;
    void solve(int start, vector<int>& nums, vector<int>& v, int k){
        if(start==nums.size()){
            int maxm = INT_MIN;
            for(int i=0;i<k;i++){
                maxm = max(maxm,v[i]);
            }
            ans = min(ans,maxm);
            return;
        }
        for(int i=0;i<k;i++){
            v[i] += nums[start];
            solve(start+1,nums,v,k);
            v[i] -= nums[start];
        }
    }
    
    int distributeCookies(vector<int>& nums, int k) { // nums is the cookies vector
        int n = nums.size();
        vector<int> v(k,0); // v is to store each sum of the k subsets
        solve(0,nums,v,k);
        return ans;
    }
};

// below is TLE

class Solution {
public:
    #define ll long long
    ll ans = INT_MAX;
    void solve(const vector<int>& cookies, int k, vector<ll>& bag,int s){
        if(s==cookies.size()){
            ll cur_max = INT_MIN;
            for(int i=0;i<k;++i){
                cur_max=max({cur_max,bag[i]});
            }
            ans = min({ans,cur_max});
            return ;
        }
        
        for(int i=0;i<k;++i){
            bag[i] += cookies[s];
            solve(cookies,k,bag,s+1);
            bag[i] -= cookies[s];
        }
        
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
    
        vector<ll> bag(k,0);
        int s=0;
        solve(cookies,k,bag,s);
        return int(ans);
    }
};