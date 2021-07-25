int Solution::findMin(const vector<int> &A) {
    int minEle=A[0];
    int l=0;
    int h=A.size()-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(A[mid]<=minEle){
            minEle=A[mid];
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return minEle;
}