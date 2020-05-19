// link : https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/tutorial/
class Solution {
public:
    
    void merge(vector<int>& nums, int left , int mid, int right) {
        int p = left ,q = mid+1,k = 0;
        vector<int> Arr(right-left+1,0);
        for(int i = left ; i<=right; ++i) {
            if(p > mid ) //checks if first part comes to an end or not .
                Arr[k++] = nums[q++]; // Note : we use post increment here
            else if(q > right)
                Arr[k++] = nums[p++];
            else if( nums[ p ] < nums[ q ])     //checks which part has smaller element.
                Arr[k++] = nums[p++];
            else
                Arr[k++] = nums[q++];
        }
        for (int p=0 ; p< k ;++p) {
            /* Now the real array has elements in sorted manner including both 
            parts.*/
             nums[ left++ ] = Arr[ p ] ;                          
        }
    }
    
    void mergeSort(vector<int>& nums, int left , int right) {
        
        if (left < right)  // base case
        { 
            int mid = left+(right-left)/2; 
  
            // Sort first and second halves 
            mergeSort(nums, left, mid); 
            mergeSort(nums, mid+1, right); 
  
            merge(nums, left, mid, right); 
        } 
        
    }
    
    vector<int> sortArray(vector<int>& nums) {
        
        mergeSort(nums,0,nums.size()-1);
        return nums;
        
    }
};

//FASTER CODE 56ms

class Solution {
public:
    
    void merge(vector<int>& nums, int left , int mid, int right) {
        int p = left ,q = mid+1,k = 0;
        int Arr[right-left+1];
        for(int i = left ; i<=right; ++i) {
            if(p > mid ) 
                Arr[k++] = nums[q++]; 
            else if(q > right)
                Arr[k++] = nums[p++];
            else if( nums[ p ] < nums[ q ])     
                Arr[k++] = nums[p++];
            else
                Arr[k++] = nums[q++];
        }
        for (int p=0 ; p< k ;++p) {
             nums[ left++ ] = Arr[ p ] ;                          
        }
    }
    
    void mergeSort(vector<int>& nums, int left , int right) {
        int mid;
        if (left < right) 
        { 
            mid = left+(right-left)/2; 
            mergeSort(nums, left, mid); 
            mergeSort(nums, mid+1, right); 
            merge(nums, left, mid, right); 
        } 
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};

// More FASTER  CODE 48ms
class Solution {
public:
    
    void merge(int nums[], int left , int mid, int right) {
        int p = left ,q = mid+1,k = 0;
        int Arr[right-left+1];
        for(int i = left ; i<=right; ++i) {
            if(p > mid ) 
                Arr[k++] = nums[q++]; 
            else if(q > right)
                Arr[k++] = nums[p++];
            else if( nums[ p ] < nums[ q ])     
                Arr[k++] = nums[p++];
            else
                Arr[k++] = nums[q++];
        }
        for (int p=0 ; p< k ;++p) {
             nums[ left++ ] = Arr[ p ] ;                          
        }
    }
    
    void mergeSort(int nums[], int left , int right) {
        int mid;
        if (left < right) 
        { 
            mid = left+(right-left)/2; 
            mergeSort(nums, left, mid); 
            mergeSort(nums, mid+1, right); 
            merge(nums, left, mid, right); 
        } 
    }
    
    vector<int> sortArray(vector<int>& num) {
        int end = num.size();
        int nums[end];
        for(int i=0 ;i <end;++i)
        {
            nums[i] = num[i];
        }
        mergeSort(nums,0,end-1);
        for(int i=0 ;i <end;++i)
        {
            num[i] = nums[i];
        }
        
        return num;
    }
};
