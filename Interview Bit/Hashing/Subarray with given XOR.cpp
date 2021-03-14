/*
Let us call the XOR of all elements in the range [i+1, j] as x, in the range [0, i] as y, and in the range [0, j] as z.

If we do XOR of y with z, the overlapping elements in [0, i] from y and z zero out and we get XOR of all elements in the range [i+1, j], i.e. x.

Since x = y XOR z, we have y = x XOR z. Now, if we know the value of z and we take the value of x as B, we get the count of x as the count of all y satisfying this relation.

Essentially, we get the count of all subarrays having XOR-sum B for each z. As we take sum of this count over all z, we get our answer.

*/

int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int>mp;
    int n=A.size(),i;
    mp.insert({0,1});
    
    int x=0,ans=0;
    if(B==0)
        ans++;
    for(i=0;i<n;i++)
    {
        x=(x^A[i]);
        
        auto it=mp.find(B^x);
        if(it!=mp.end())
        {
            ans+=it->second;
        }
        mp[x]++;
    }
    return ans;
}