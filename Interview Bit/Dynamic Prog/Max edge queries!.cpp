#define mp make_pair
#define pb push_back
#define ar array
vector< ar<int,2> >graph[100010];
int level[100010];
int dp[100010][18],mx[100010][18];
void dfs(int u,int h)
{
    dp[u][0] = h;
    if(h!=-1)
        level[u] = level[h]+1;
    for(int i=0;i<graph[u].size();i++)
    {
        int v = graph[u][i][0];
        if(v==h)
            continue;
        int wt = graph[u][i][1];
        dfs(v,u);
        mx[v][0] = wt;
    }
    return;
}
void precal(int n)
{
    for(int h=1;h<18;h++)
    {
        for(int i=0;i<n;i++)
        {
            if(dp[i][h-1]!=-1)
            {
                dp[i][h] = dp[dp[i][h-1]][h-1];
                mx[i][h] = max(mx[i][h-1],mx[dp[i][h-1]][h-1]);
            }
        }
    }
}
int comp(int a,int b)
{
    if(level[a]<level[b])
        swap(a,b);
    int ans=0;
    for(int i=17;i>=0;i--)
    {
        if(level[a]-(1<<i)>=level[b])
        {
            ans = max(ans,mx[a][i]);
            a = dp[a][i];
        }
    }
    if(a==b)
        return ans;
    for(int i=17;i>=0;i--)
    {
        if(dp[b][i]!=-1 && dp[b][i]!=dp[a][i])
        {
            ans = max(ans,mx[a][i]);
            ans = max(ans,mx[b][i]);
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    ans = max(ans,mx[a][0]);
    ans = max(ans,mx[b][0]);
    return ans;
}
vector<int> Solution::solve(vector<vector<int> > &A, vector<vector<int> > &B) 
{
    int n = A.size()+1;
    for(int i=0;i<n;i++)
    {
        graph[i].clear();
    }
    for(int i=0;i<A.size();i++)
    {
        int u = A[i][0], v = A[i][1], w = A[i][2];
        graph[u-1].pb({v-1,w});
        graph[v-1].pb({u-1,w});
    }
    level[0] = 0;
    memset(dp,-1,sizeof(dp));
    dfs(0,-1);
    precal(n);
    vector<int>ans;
    for(int i=0;i<B.size();i++)
    {
        int u = B[i][0]-1;
        int v = B[i][1]-1;
        int x = comp(u,v);
        ans.pb(x);
    }
    return ans;
}

