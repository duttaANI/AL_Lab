class Solution {
public:
    
    vector<int> fKadane,rKadane;
    
    int maximumSum(vector<int>& nums) {
        
        int max_cur=nums[0],max_global = nums[0],ans=INT_MIN;
        fKadane.push_back(max_cur);
        for (int i = 1; i<nums.size();++i)
        {
            max_cur = max(nums[i],max_cur+nums[i]);
            max_global = max({max_cur,max_global});
            fKadane.push_back(max_cur);
        }
        
        ans = max_global;
        
        reverse(nums.begin(),nums.end());
        
        max_cur=nums[0],max_global = nums[0];
        rKadane.push_back(max_cur);
        for (int i = 1; i<nums.size();++i)
        {
            max_cur = max(nums[i],max_cur+nums[i]);
            // max_global = max({max_cur,max_global});
            rKadane.push_back(max_cur);
        }
        
        reverse(rKadane.begin(),rKadane.end());
        
//         for(int i : fKadane){
//             cout << i << " ";
//         }
//         cout << endl;
        
//         for(int i : rKadane){
//             cout << i << " ";
//         }
//         cout << endl;
        
        
        ans = max(ans,max_global);
        for(int i=1; i+1<fKadane.size(); ++i ){
            ans = max({ ans, fKadane[i-1] + rKadane[i+1]  });
        }
        return ans;
    }
};