// link : https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/discuss/1132781/C%2B%2B-Graph-Thinking-O(N)-or-O(1)
class Solution {
public:
    int reinitializePermutation(int n) {
        int res = 0, i = 1;
        while (res == 0 || i > 1) {
            if (i < n / 2)
                i *= 2;
            else
                i = (i - n / 2) * 2 + 1;
            res++;
        }
        return res;
    }
};