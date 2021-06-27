int Solution::solve(vector<int> &A, int B) {
    
    int cur=0;
    int n = A.size();
    int ans =0;
    while(cur<n){
        int next = cur+B-1;
        
        int prev = cur-B+1;
        if(prev<0)
            prev = 0;
        while(next>=prev){
            if(A[next]){
                // cout << next << endl;
                break;
            }
            next--;
        }
        if(next>=prev){
            cur = next+B;
            ++ans;
        }
        else{
            return -1;
        }
    }
    return ans; 
}
