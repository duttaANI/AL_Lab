class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> odd,eve,ans(n,0);
        for(int i=0;i<n;i+=2){
            eve.push_back(nums[i]);
        }
        for(int i=1;i<n;i+=2){
            odd.push_back(nums[i]);
        }
        sort(eve.begin(),eve.end());
        sort(odd.begin(),odd.end());
        reverse(odd.begin(),odd.end());
        
        
        for(int i=0;i<n;++i){
            if(!(i%2)){
                ans[i] = eve[i/2];
            }
            else{
                ans[i] = odd[i/2];
            }
        }
        
        return ans;
    }
};