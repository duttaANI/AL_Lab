// link: https://leetcode.com/problems/gas-station/discuss/42572/Proof-of-%22if-total-gas-is-greater-than-total-cost-there-is-a-solution%22.-C%2B%2B
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totSum = 0 ,start =0, partSum=INT_MAX;
        for (int i=0; i<n; ++i){
            totSum += gas[i] - cost[i];
            if (totSum < partSum){
                partSum = totSum;
                start = i+1;
            }
        }
        return (totSum<0)? -1:(start%n) ;
    }
};