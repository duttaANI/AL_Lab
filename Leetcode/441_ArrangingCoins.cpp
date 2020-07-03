// link :https://leetcode.com/problems/arranging-coins/
// Math
class Solution {
public:
    int arrangeCoins(int n) {
        return (int)(sqrt(2 * (long)n + 0.25) - 0.5);
    }
};

// Binary search
class Solution {
public:
    int arrangeCoins(int n) {
        long left = 0, right = n;
        long curr,k;
        while (left <= right) {
            k = left + (right-left)/2;
            curr = k*(k+1)/2;
            if (curr == n) return k;
            if(n<curr){
                right = k-1;
            }else{
                left=k+1;
            }
        }
        return(int)right;
    }
};

//My code slow 
class Solution {
public:
    int arrangeCoins(int n) {
        int ans = 0;
        for (int i=1; n>=0; ++i ) {
            n = n - i;
            if(n>=0){
                ++ans;
            }
            else
                return ans;
        }
        return ans;
    }
};