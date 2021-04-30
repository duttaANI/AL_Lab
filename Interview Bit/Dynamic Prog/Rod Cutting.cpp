void getAns(vector<int> &ans, vector<vector<int>> &dp, int i, int j, vector<int> p) {
    if (i + 1 == j) return ;
    for (int k = i + 1; k < j; k++) {
        if (dp[i][k] + dp[k][j] + p[j] - p[i] == dp[i][j]) {
            ans.push_back(p[k]);
            getAns(ans, dp, i, k, p);
            getAns(ans, dp, k, j, p);
            return ;
        }
    }
    return ;
}
vector<int> Solution::rodCut(int A, vector<int> &B) {
    vector<int> p;
    p.push_back(0);
    for (int b: B) {
        p.push_back(b);
    }
    p.push_back(A);
    sort(p.begin(), p.end());
    
    int n = p.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i + l - 1 < n; i++) {
            dp[i][i+l-1] = INT_MAX;
            for (int k = i + 1; k < i + l - 1; k++){
                dp[i][i+l-1] = min(dp[i][i+l-1], dp[i][k] + dp[k][i+l-1] + p[i+l-1] - p[i]);
            
                // cout << i << " " << i+l-1 << " " << dp[i][i+l-1] << endl;
            }
        }
    }
    
    // JUST PRINTING ANS
    vector<int> ans;
    getAns(ans, dp, 0, n - 1, p);
    return ans;
    
}

// Nayan -> 

vector<int> res;
int calculate(int i,int j,int l ,int r,vector<vector<int>>& dp,vector<int>& cuts){
    if(i<0||i>j||j>=cuts.size())return 0;
    if(i==j)return r-l;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=INT_MAX,prev;
    for(int k=i;k<=j;k++){
        prev=ans;
        ans=min(ans,(r-l)+calculate(i,k-1,l,cuts[k],dp,cuts)+calculate(k+1,j,cuts[k],r,dp,cuts));
        if(ans<prev){
            if(res.size())res.pop_back();
            res.push_back(cuts[k]);
        }
    }
    dp[i][j]=ans;
    return dp[i][j];
}


vector<int> Solution::rodCut(int A, vector<int> &B) {
    res.clear();
    sort(B.begin(),B.end());
    vector<vector<int>> dp(B.size(),vector<int>(B.size(),-1));
    int mincost = calculate(0,B.size()-1,0,A,dp,B);
    // for(auto a : dp){
    //     for(auto b : a){
    //         cout<<b<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<mincost<<endl;
    return res;
}

// my below doesnt work

// unordered_map<int,vector<int>> costPath;
// unordered_map<string,int> mincost; // min cost from i to j cuts
// vector<int> C;
// int solve(int l,int r, vector<int>& path, int  cost){
//     if(l<r){
//         cout << C[l] << " " << C[r] << endl;
//         string str = to_string(l) + " " + to_string(r);
//         if( mincost.find(str)!=mincost.end() ){
//             return mincost[str];
//         }
        
//         int mini = INT_MAX;
//         for(int k=l+1;k<r;++k){
//             path.push_back(C[k]);
//             mini =   min({ mini , cost + solve(l,k,path,cost+(C[k]-C[l])) , cost + solve(k,r,path,cost+(C[r]-C[k])) });
//             path.pop_back();
//         }
//         return mincost[str] = mini;
//     }
//     else{
//         cout << " PAth: ";
//         for(int i=0;i<path.size();++i){
//             cout << path[i] << " ";
//         }
//         cout << endl;
//         if(costPath.find(cost)==costPath.end())
//         costPath[cost] = path;
//     }
// }

// vector<int> Solution::rodCut(int A, vector<int> &B) {
//     sort(B.begin(),B.end());
//     C.clear();
//     C.push_back(0);
//     for(int i=0;i<B.size();++i){
//         C.push_back(B[i]);
//     }
//     C.push_back(A);
//     vector<int> path;
//     int cost =A;
//     int r = C.size()-1;
//     int mini = solve(0,r,path,cost);
    
//     return costPath[mini];
// }

