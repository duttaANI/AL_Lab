// link: https://www.youtube.com/watch?time_continue=13&v=uJ8BAQ8lASE&feature=emb_logo
// link2 : https://leetcode.com/problems/split-array-into-consecutive-subsequences/discuss/106493/C%2B%2B-O(n)-solution-two-pass
class Solution {
public:
    bool isPossible(vector<int>& nums) {
      
        unordered_map<int,int> cnt, tails;
        for(int &i : nums) cnt[i]++;
        for(int &i : nums){
            if(!cnt[i]) continue;
            cnt[i]--;
            if(tails[i-1]>0){
                tails[i-1]--;
                tails[i]++;
            }
            else if(cnt[i+1] && cnt[i+2]){
                cnt[i+1]--;
                cnt[i+2]--;
                tails[i+2]++;
            }
            else return false;
        }
        
        return true;
    }
};