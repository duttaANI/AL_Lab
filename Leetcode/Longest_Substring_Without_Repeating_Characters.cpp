class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>dict(256,-1); // since there are 256 char in cpp , declare a vector with 256 entries = -1
        int maxlen = 0, start = -1,i;
        for(i=0;i<s.size();++i){
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxlen = (maxlen > (i - start)) ? maxlen : (i-start);
        }
        return maxlen;
        
    }
};