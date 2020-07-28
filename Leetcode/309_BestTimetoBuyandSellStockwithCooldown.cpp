// link :

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN, sell = 0, prev_sell=0, prev_buy;
        for( int price : prices ){
            prev_buy = buy;
            buy = max( prev_sell - price, buy );
            prev_sell = sell;
            sell = max( prev_buy + price, sell );
        }
        return sell;
    }
};

// first attempt

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
        
        int n = prices.size()  ;
        if(n==0 || n==1) return 0;
        vector<int> dp(n,0) ;
        dp[0] = 0;
        dp[1] = max(prices[1] - prices[0], dp[0]);
        
        if( n>=3 )
            dp[2] = max( prices[2]-prices[1], dp[1] );
        if( n>=4 )
            dp[3] = max( prices[3]-prices[2], dp[2] );
        for(int i = 4; i<n; ++i){
            
            //cout <<  max( dp[i-3] + prices[i] - prices[i-1], dp[i-1] ) << "\n";
            dp[i] = max( dp[i-3] + prices[i] - prices[i-1], dp[i-1] );
        }
        
        return dp[n-1];
    }
};