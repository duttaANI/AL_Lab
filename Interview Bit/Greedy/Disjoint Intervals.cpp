bool cmp(vector<int>&a ,vector<int>&b){
    return a[1]<b[1];
}
int Solution::solve(vector<vector<int> > &A) {
    sort(A.begin(),A.end(),cmp);
    int n = A.size();
    if(n==0 )return 0;

    int count =1,endtime=A[0][1];
    for(int i=1;i<n;++i){
        if(A[i][0] > endtime){
            count++;
            endtime = A[i][1];
        }
    }
    return count;
}
