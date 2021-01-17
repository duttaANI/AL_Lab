class Solution {
public:
    
    bool isPalindromeRange(string s, int i, int j) {
        for (int k = i; k <= i + (j - i) / 2; k++) {
            if ( s[k] != s[j - k + i] ) return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        for (int i = 0; i < s.length() / 2; i++) {
            if ( s[i] != s[s.length() - 1 - i] ) {
                int j = s.length() - 1 - i;
                return (isPalindromeRange(s, i+1, j) ||
                        isPalindromeRange(s, i, j-1));
            }
        }
        return true;
    }
};