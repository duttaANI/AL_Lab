class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        cost.push_back(0);
        int n = cost.size();
        
        vector<int> min_cost (n, 0);
        
        min_cost[0] = cost[0]; min_cost[1] = cost[1];
        
        for (int i=2; i<n ; ++i) {
            min_cost[i] = min( min_cost[i-2]+cost[i], min_cost[i-1] + cost[i] );
        }
        
        return min_cost[n-1];
    }
};