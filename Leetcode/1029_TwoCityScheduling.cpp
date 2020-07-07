// link : https://leetcode.com/problems/two-city-scheduling/discuss/667786/Java-or-C%2B%2B-or-Python3-or-With-detailed-explanation
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size()/2;
        vector <int> refund ;
        int minCost=0;
        for (vector<int> cost : costs){
            minCost += cost[0];
            refund.push_back(cost[1]-cost[0]);
        }
        sort(refund.begin(),refund.end());
        for(int i=0; i<n; ++i){
            minCost += refund[i];
        }
    
        return minCost;
    }
};