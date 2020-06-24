// link :https://leetcode.com/problems/length-of-last-word/discuss/21892/7-lines-4ms-C%2B%2B-Solution
class Solution {
public:
    int lengthOfLastWord(string s) {
        int tail = s.length() - 1;
        int len=0;
        while (tail >= 0 && s[tail] == ' ') tail--;
        while( tail>=0 && s[tail]!=' ' ) {
            --tail;
            ++len;
        }
        return len;
    }
};