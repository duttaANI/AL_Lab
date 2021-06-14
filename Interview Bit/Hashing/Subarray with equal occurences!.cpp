int Solution::solve(vector<int> &A, int B, int C) {
    // Add 1 if it is B 
    // Sub 1 if it is C
    // Else do nothing
    
    int sum=0,ans=0;
    
    unordered_map<int,int> seen;
    seen[0]=1;
    
    for(int i=0;i<A.size();i++){
        
        if(A[i]==B){
            sum++;
        }else if(A[i]==C){
            sum--;
        }
        
        if(seen.find(sum)!=seen.end()){
            ans += seen[sum];
        }
        seen[sum]++;
    }
    return ans;
}
