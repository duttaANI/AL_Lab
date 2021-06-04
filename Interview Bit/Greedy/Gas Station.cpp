int Solution::canCompleteCircuit(const vector<int>& A, const vector<int>& B) {
    int ans=0,cap=0,total=0;

    int n = A.size();
    
    for(int i=0;i<n;i++)
    {
        cap+= A[i]-B[i];
        
        if(cap<0)
        {
            ans=i+1;
            total +=cap;
            cap=0;
        }
    }
    
    if(total + cap<0)
    return -1;
    else
    return ans;

}