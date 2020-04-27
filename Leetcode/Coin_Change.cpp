#include <iostream>
#include <bits/stdc++.h> 
#include <cstdlib>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    int coinChange2(vector<int>& coins, int rem_amt, vector<int>& dp_arr)
    {
        if(rem_amt  <0) return -1;
        if(rem_amt ==0) return  0;
        if(dp_arr[rem_amt-1]!=0) return dp_arr[rem_amt-1];
        int min_coins = 2147483647;
        
        for(int i=0; i< coins.size();++i)
        {
            int res = coinChange2(coins,rem_amt - coins[i], dp_arr);
            if(res>=0 && res < min_coins)
            {
                min_coins = res+1;
            }
        }
        dp_arr[rem_amt-1] = (min_coins == 2147483647 )? -1:min_coins;
        return dp_arr[rem_amt-1];
       
    }
    
    int coinChange(vector<int>& coins, int amount) {
        if(amount < 1)
            return 0;
        vector<int> dp_arr(amount,0);
        return coinChange2(coins,amount,dp_arr);
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> coins = stringToIntegerVector(line);
        getline(cin, line);
        int amount = stringToInteger(line);
        
        int ret = Solution().coinChange(coins, amount);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}