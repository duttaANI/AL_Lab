vector<int> Solution::searchRange(const vector<int> &A, int B) {
    // for expansion once ele found
    int gol , gor;
    int n = A.size();
    
    // for bin s
    int l =0 , r = n-1, mid;
    while(l<=r){
        mid = l + (r-l)/2;
        if( A[mid] == B  ){
            break;
        }
        else if (  A[mid] < B ){
            l=mid+1;
        }
        else{
            r = mid-1;
        }
    }
    
    if( A[mid]!=B  ){
        return {-1,-1};
    }
    
    // expand
    gol = mid,gor=mid;
    while( gol>=0 && A[gol]==B ){
        --gol;
    }
    
    while(  gor<n && A[gor]==B ){
        ++gor;
    }
    
    return { gol+1,gor-1 };
}