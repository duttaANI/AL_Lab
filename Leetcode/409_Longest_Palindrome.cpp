class Solution {
public:
    int longestPalindrome(string s) {
        int count=0;
        int odd_flag=0;
        vector<int> freq_map(256,0);
        for(int i=0; i<s.length();++i)
        {
            freq_map[s[i]]++;
        }
        
        for(int i =0 ; i<256;++i)
        {
            if( freq_map[i] >0 && freq_map[i]%2 == 0 ) count = count + freq_map[i];
            else if(freq_map[i] >0){
                odd_flag = 1;
                count = count + (freq_map[i] - freq_map[i]%2);
            }
        }
        
        return count + odd_flag;
        
    }
};