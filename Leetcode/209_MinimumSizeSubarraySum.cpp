// similar to : https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(); 
        if(n==0) return 0;
        int ans = n+1;
        deque<int> dq;
        for(int i=0;i<n;++i){
            if(i!=0){
                nums[i]+=nums[i-1];
            }
            
            if(nums[i]>=s){
                ans = min({ans, i+1 });
            }
            
            while( dq.size() && nums[i]-nums[dq.front()]>=s ){
                ans = min({ans, i-dq.front() });
                dq.pop_front();
            }
            
            dq.push_back(i);
        }
        return (ans!=n+1)?ans:0;
    }
};


///////////////////////////////
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(); int ans = n+1;
        int left = 0; int sum = 0;
        for (int i=0; i<n; i++) {
            sum = sum + nums[i];
            while(sum>=s) {
                ans = min(ans,i+1-left);
                sum = sum - nums[left++];
            }
        }
        return (ans!=n+1)?ans:0;
    }
};
