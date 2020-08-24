// x >>= 1 means "set x to itself shifted by one bit to the right"

// link :https://leetcode.com/problems/minimum-numbers-of-function-calls-to-make-target-array/discuss/805740/JavaC%2B%2BPython-Bit-Counts

class Solution {
public:
    int minOperations(vector<int>& A) {
        int res = 0, maxLen = 0;
        for (int a : A) {
            int bits = 0;
            while (a > 0) {
                res += a & 1;
                bits++;
                a >>= 1;
            }
            maxLen = max(maxLen, bits);
        }
        return res + maxLen - 1;
    }
};

// following attempt didnt work

class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        vector<int> twosPower(n,0);
        
        int power = 0;
        for(int i=0; i<n; ++i){
            while( nums[i] >= pow(2,power) ){
                ++power;
            }
            cout << power << "\n";
            twosPower[i] = max(power-1,0) ;
        }
        int ans = 0,nb=1;
        for(int i=1; i<n; ++i){
            while( twosPower[i-1]==twosPower[i] ){
                nb++;
                ++i;
            }
            ans += nb + twosPower[i-1];
            nb = 1;
            cout << ans << "1\n";
        }
        for(int i=0; i<n; ++i){
            
            ans += nums[i] - pow(2,twosPower[i]);
            cout << ans << "\n";
        }
        return ans;
    }
};
