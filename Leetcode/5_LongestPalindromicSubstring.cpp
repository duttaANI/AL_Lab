class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.size() < 2)
            return s;
        int len = s.size(), max_left = 0, max_len = 1, left, right;
        for (int start = 0; start < len && len - start > max_len / 2;) {
            left = right = start;
            while (right < len - 1 && s[right + 1] == s[right])
                ++right;
            start = right + 1;
            while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                ++right;
                --left;
            }
            if (max_len < right - left + 1) {
                max_left = left;
                max_len = right - left + 1;
            }
        }
        return s.substr(max_left, max_len);
    }
};


// class Solution {
// public:
//     string expand(string str, int low, int high)
//     {
//         int len = str.length();
//         while(low>=0 && high<len && str[low]==str[high])
//         {
//             --low;    ++high;
//         }
//         return str.substr(low+1,high-low-1); 
//     }
    
//     string longestPalindrome(string s) {
//         if(s.length()==0 || s.length()==1)
//         {
//             return s;
//         }
        
//         // max_str stores the maximum length palindromic substring
// 	    // found so far
    
// 	    string max_str = "", cur_str;
        
//         int max_len=0,cur_len,i;
        
//         for( i=0; i < s.length() - 1 ; ++i)
//         {
//             //------------For odd length
//             cur_str = expand(s,i,i);
//             cur_len = cur_str.length();
            
//             if(cur_len > max_len)
//             {
//                 max_len = cur_len;
//                 max_str = cur_str;
//             }
            
//             //------------For even length
//             cur_str = expand(s,i,i+1);
//             cur_len = cur_str.length();
            
//             if(cur_len > max_len)
//             {
//                 max_len = cur_len;
//                 max_str = cur_str;
//             }
            
//         }
        
//         return max_str;
//     }
// };