class Solution
{
  public:
    int subArraySum(int a[], int n, int k)
    {
    	//code here.
    	int ans = 0;
    	unordered_map<int,vector<int>> mp;
    	int sum = 0;
    	mp[0].push_back(-1);
    	for(int i=0;i<n;++i){
    	    sum += a[i];
    	    if( mp.find( sum-k )!=mp.end() ){
    	        ans += mp[sum-k].size();
    	    }
    	    mp[sum].push_back(i);
    	}
    	return ans;
    }
};