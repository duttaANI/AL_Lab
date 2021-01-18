// link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/Most-consistent-ways-of-dealing-with-the-series-of-stock-problems

// Pay while buying stock
class Solution {
public:
    
    int maxProfit(vector<int>& prices, int fee) {
        int T_ik0 = 0, T_ik1 = INT_MIN;

        for (int price : prices) {
            int T_ik0_old = T_ik0;
            T_ik0 = max(T_ik0, T_ik1 + price);
            T_ik1 = max(T_ik1, T_ik0_old - price - fee);
        }

        return T_ik0;
    }
};