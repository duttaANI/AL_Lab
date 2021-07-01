vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int l =0;
    int r =A.size()-1;
    // cout << r << endl;
    while( l<r ){
        int mid = l + (r-l)/2;
        if( A[mid]>B ){
            r = mid-1;
        }
        else if ( A[mid]<B ){
            l = mid+1;
        }
        else{
            int temp = mid;
            while( A[temp]==B ){
                --temp;
            }
            l = temp+1;
            temp = mid;
            while( temp<A.size() && A[temp]==B  ){
                ++temp;
            }
            if(temp==A.size()-1) 
                r = A.size()-1;
            else
                r = temp-1;
            return {l,r};
        }
    }
    if( A[l]!=B || A[r]!=B ){
        return {-1,-1};
    }
    return {l,r};
}
