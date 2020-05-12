class Solution {
public:
    string minWindow(string s, string t) {
        
        if(s.empty() || t.empty()) return "";
        
        string result;
        
        // Dictionary which keeps a count of all the unique characters in t.
        unordered_map<char, int> dictT;
        for (int i=0; i<t.length(); ++i)
        {
            dictT[t[i]]++;
        }
        
        // Left and Right pointer
        int l = 0, r = 0, letterCounter=0;
        int minLength = INT_MAX;
        
        // Dictionary which keeps a count of all the unique characters in the current window.
        unordered_map<char, int> windowCounts;
        
        for(r=0;r<s.length();++r)
        {
            char c = s[r];
            
                if(dictT.find(c) != dictT.end()){
                    windowCounts[c]++;

                    if(windowCounts[c]==dictT[c])
                        letterCounter++;
                }
            
            if(letterCounter >= dictT.size()){
                while (dictT.find(s[l]) == dictT.end() || windowCounts[s[l]]> dictT[s[l]])
                {
                    windowCounts[s[l]]--;
                    ++l;
                }
                if(r-l+1 < minLength)
                {
                    minLength = r-l+1;
                    result = s.substr(l,minLength);
                }
            }
            
        }
        
        return result;
    }
};