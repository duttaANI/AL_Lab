int Solution::uniquePaths(int A, int B) {
    int m=A-1;
    int r=B-1;
    int N=m+r;
    if(m<r) swap(m,r); // so we get n smaller
    
    long long int mul=1;
    for(int i=0;i<r;i++)
    {
        mul*=N;
        N--;
    }// here... we have expanded N! only by r nums ..like 8*7.
    
    long long fact=1;
    for(int i=2;i<=r;i++) fact*=i; // r!
    
    mul/=fact;
    
    return mul;
}