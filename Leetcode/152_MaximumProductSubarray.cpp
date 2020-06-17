// link : https://www.techiedelight.com/find-maximum-product-subarray-given-array/
class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
       
        int max_ending =nums[0]; int min_ending =nums[0];
        int max_so_far =nums[0];
        int temp;
        for (int i=1 ;i <n; ++i) {
            
            temp = max_ending;
            
            max_ending = max ( nums[i] , max ( nums[i]*min_ending , temp*nums[i]) );
            
            min_ending = min ( nums[i] , min ( nums[i]*min_ending , temp*nums[i]) );
            
            max_so_far = max (max_so_far , max_ending);
            
        }
        return max_so_far;
    }
};