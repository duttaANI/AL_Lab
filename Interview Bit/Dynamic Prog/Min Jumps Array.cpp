#define ar array
int Solution::jump(vector<int> &A) {
    
    int n=A.size(),jumps=0,reach=0,maxJump=0;
    for(int i=0;i<n-1;i++){
        maxJump=max(maxJump,i+A[i]);
        if(i==reach){
            jumps++;
            reach=maxJump;
        }
    }
    if(reach<n-1) return -1;
    return jumps;

    // int start=0, end=0, maxend=0, steps=0, n=nums.size();
        
    // while(end < n-1)
    // {
    //     ++steps;
    //     for (int i=start; i<=end; ++i)
    //     {
    //         maxend = max(nums[i] + i,maxend);
    //     }
    //     start = end;
    //     end = maxend;
    // }
    // if(maxend>=n-1)
    //     return steps;
    // else{
    //     return -1;
    // }
    
    
    // BFS
    // int n = A.size();
    // vector<int> vis(n,0);
    // queue<ar<int,3>> q;
    // q.push({0,A[0],0});
    // vis[0]=1;
    // while(!q.empty()){
    //     ar<int,3> frnt = q.front(); q.pop();
    //     if(frnt[0]==n-1){
    //         return frnt[2];
    //     }
    //     for(int j=1;frnt[0]+j<n && j<=frnt[1]; ++j){
    //         if(!vis[frnt[0]+j]){
    //             vis[frnt[0]+j] = 1;
    //             if(frnt[0]+j==n-1){
    //                 return frnt[2]+1;
    //             }
    //             q.push({frnt[0]+j,A[frnt[0]+j],frnt[2]+1});
    //         }
    //     }
    // }
    // return -1;
}
