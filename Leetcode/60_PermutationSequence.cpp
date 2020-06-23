class Solution {
public:
    
    void swap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    void reverse(vector<int> &nums, int start) {
        int i = start, j = nums.size() - 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        if ( i>=0 ) {
            int j = nums.size() - 1;
            while(j>=0 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums, i, j);
        }
        reverse(nums, i + 1);
    }
    
    string getPermutation(int n, int k) {
        
        vector<int>initial (n,0);
        for (int i=1; i<n+1; ++i){
            initial[i-1] = i; 
        }
        
        for(int i=0; i<k-1 ;++i) {
            nextPermutation( initial );
        }
        
//         for(int i=0; i<n; ++i)
//             cout << initial[i] << " ";
        
        string str = "";
        
        for (int i=0; i<n; ++i)
            str.append( to_string(initial[i]) );
        
        
        return str;
    }
};