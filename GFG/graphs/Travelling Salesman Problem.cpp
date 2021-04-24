class Solution {
public:



    int t[1025][11];
    
    int Solve(int mask , int pos, int n, vector<vector<int>> cost){
    	if(mask==(1<<n)-1){
    		return cost[pos][0];
    	}
    
    	int ans = INT_MAX;
    
    	if(t[mask][pos]!=-1) return t[mask][pos];
    
    	for(int i=0;i<n;++i){
    		if( (mask&(1<<i)) ==0 ) // not visited
    		{
    			int temp = cost[pos][i] + Solve(mask|(1<<i),i,n,cost);
    			ans = min({ans,temp});
    		}
    	}
    
    	return t[mask][pos] = ans;
    }
    
    int total_cost(vector<vector<int>>cost){
        // Code here
        int n = cost.size();
        memset(t,-1,sizeof(t));
        return Solve(1,0,n,cost);
    }
};