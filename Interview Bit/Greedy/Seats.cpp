int Solution::seats(string A) {
    int n=A.size();
    
    vector<int> pos;
    
    for(int i=0;i<n;i++)
    {
        if(A[i]=='x') pos.push_back(i);
    }
    
    int mid=pos.size()/2;
    int ans=0;
    
    for(int i=0;i<pos.size();i++)
    {
        int start=pos[i];
        int dest=pos[mid]-(mid-i);
        
        ans=(ans+abs(dest-start))%10000003;
    }
       
    return ans;
}
