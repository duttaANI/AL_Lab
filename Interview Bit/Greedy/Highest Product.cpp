int Solution::maxp3(vector<int> &A) {
    int n=A.size();
    long long ans=INT_MIN;
    sort(A.begin(),A.end());
    ans=A[0]*A[1]*A[n-1];
    ans=max(ans,(long long int)A[n-1]*A[n-2]*A[n-3]);
    return ans;
}