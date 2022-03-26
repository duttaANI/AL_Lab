vector<vector<vector<bool>>> dp;
vector<int> arr;
vector<int>res;
int n;

bool possible(int idx,int cur_size,int cur_sum)
{
    if(cur_size==0) return (cur_sum==0);
    if(idx==n) return false;
    
    if(dp[idx][cur_size][cur_sum]==false) return false;
    if(cur_sum>=arr[idx])
    {
        res.push_back(arr[idx]);
        if(possible(idx+1,cur_size-1,cur_sum-arr[idx])) return true;
        res.pop_back();
    }
    if(possible(idx+1,cur_size,cur_sum)) return true;
    return dp[idx][cur_size][cur_sum]=false;
}
vector<vector<int> > Solution::avgset(vector<int> &A) {
    
    arr.clear();
    res.clear();
    dp.clear();
    
    arr=A;
    int sum=0;
    n=A.size();
    for(int i=0;i<n;i++) sum+=A[i];
    dp.resize(n,vector<vector<bool>>(n,vector<bool>(sum+1,true)));
    
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    for(int i=1;i<=n/2;i++)
    {
        if(sum*i %n==0)
        {
            int cur_sum=(sum*i)/n;
            if(possible(0,i,cur_sum)) 
            {
                vector<int> res2;
                int p1=0,p2=0;
                while(p2<n ||p1<i)
                {
                    if(p1<i && res[p1]==arr[p2]){p1++;p2++;}
                    else
                    {
                        res2.push_back(arr[p2]);
                        p2++;
                    }
                }
                ans.push_back(res);
                ans.push_back(res2);
                return ans;
            }
        }
    }
    return ans;
}
