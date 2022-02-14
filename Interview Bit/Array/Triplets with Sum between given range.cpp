int Solution::solve(vector<string> &A) {
    int i=0;
    int j=A.size()-1;
    sort(A.begin(),A.end());
    while(i<j-1)
    {
        int mid=(i+j)/2;
        double x=stof(A[i]);
        double y=stof(A[mid]);
        double z=stof(A[j]);
        double sum=x+y+z;
        if(sum>=2)
        {
            j--;
        }
        else if(sum<=1)
        {
            i++;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}
