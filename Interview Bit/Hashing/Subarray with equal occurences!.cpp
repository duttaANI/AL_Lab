int Solution::solve(vector<int> &a, int b, int c) {
    int sum=0,ans=0;
    unordered_map<int,int> m;
    m[0] = 1;
    for(int i : a)
    {
        if(i == b) sum += 1;
        else if(i == c) sum += -1;
        ans += m[sum];
        m[sum]++;
    }
    return ans;
}