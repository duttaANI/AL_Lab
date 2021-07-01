int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int l =0;
    int r = A.size()*A[0].size() - 1;
    int row = A[0].size();
    while( l<=r ){
        int mid = l + (r-l)/2;
        int i = mid/row;
        int j = mid%row;
        if( A[i][j] > B ){
            r = mid-1;
        }
        else if ( A[i][j] < B ){
            l = mid+1;
        }
        else{
            return 1;
        }
    }
    return 0;
}
