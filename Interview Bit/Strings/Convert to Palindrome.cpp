int Solution::solve(string A)
{
    int len=A.size();
    int count=0;
    int i=0,j=len-1;
    
    while(i<j)
    {
        if(A[i]==A[j])
        {
            i++;j--;
        }
        else if(A[i+1]==A[j])
        {
            i++;
            count++;
            if(count>1) return 0;
        }
        else if(A[j-1]==A[i])
        {
            j--;
            count++;
            if(count>1) return 0;
        }
        else return 0;
    }
    if(count<=1) return 1;
    else return 0;
}