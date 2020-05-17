class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if(nums.size()==0)
            return -1;
        
        int left = 0,mid;
        int right = nums.size() - 1;
        while( left < right ){
            
            mid = left + (-left+right)/2;
            if(nums[mid] > nums[right]) left = mid+1;
            else right = mid;
        }
        
        int pivot = left;
        
        // double bin search
        int left1=0; int right1 = pivot-1;
        while( right1>0 && left1<right1 )
        {
            mid = left1 + (-left1+right1)/2;
            if(nums[mid] < target) left1 = mid+1;
            else right1 = mid;
            
        }
        if(nums[left1]==target) return left1;
        
        int left2=pivot ; int right2 = nums.size()-1;
        while( left2<right2 )
        {
            mid = left2 + (-left2+right2)/2;
            if(nums[mid] < target) left2 = mid+1;
            else right2 = mid;
            
        }
        if(nums[left2]==target) return left2;
        //cout << left2 << "\n";
        return -1;
    }
};