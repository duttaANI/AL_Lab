class Solution {
public:
    
    bool BinSearch (vector<int> row, int target) {
        int low=0;
        int high = row.size()-1;
        int mid;
        while(low<=high) {
            mid = low + (high-low)/2;
            if (target==row[mid])
            {
                return true;
            }
            else if(target > row[mid])
            {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i=0 ;i<matrix.size(); ++i) {
            if (BinSearch(matrix[i] , target) )
                return true;
        }
        return false;
    }
};