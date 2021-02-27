// use --hi when duplicates are seen

class Solution {
public:
    int findMin(vector<int>& num) {
        int lo = 0;
        int hi = num.size() - 1;
        int mid = 0;
        
        while(lo < hi) {
            mid = lo + (hi - lo) / 2;
            
            if (num[mid] > num[hi]) {
                lo = mid + 1;
            }
            else if (num[mid] < num[hi]) {
                hi = mid;
            }
            else { // when num[mid] and num[hi] are same
                hi--;
            }
        }
        return num[lo];
    }
};



// TLE

class Solution {
public:
    int findMin(vector<int>& nums) {
        int r = nums.size()-1;
        int l=0;
        while(l<r){
            int mid = (l+r)/2;
            if( nums[mid]>nums[l] ){
                r=mid-1;
            }else{
                l=mid;
            }
        }
        return nums[l];
    }
};