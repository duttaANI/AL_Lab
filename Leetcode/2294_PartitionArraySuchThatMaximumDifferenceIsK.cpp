// O(n)
const int ZERO = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool a[100005];
    
    int partitionArray(vector<int>& nums, int k) {
        int mx = -1;
        for(int num: nums){
            a[num] = 1;
            mx = max(num, mx);
        }
        
        int ans = 0;
        int l = 0;
        while(l <= mx){
            while(l <= mx && !a[l]) l++;
            l += k + 1;
            while(l <= mx && !a[l]) l++;
            ans++;
        }
        
        return ans;
    }
};

// Below nlog(n)
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int ans  = 1;
        sort(nums.begin(),nums.end());
        int cur_min = nums[0];
        int n = nums.size();
        for(int i=1;i<n;++i){
            if(nums[i]-cur_min>k){
                cur_min = nums[i];
                ++ans;
            }
        }
        return ans;
    }
};