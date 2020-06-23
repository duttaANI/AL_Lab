
// DP
   vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
   {
      if (words.empty()) return {};
     
      // sort words by length
      sort(words.begin(), words.end(), [](string& s1, string& s2) { return s1.size() < s2.size(); });
     
      // min length of words 
      minL = words[0].size();
     
      for (auto& w:words) {
        if (wordBreak(w)) res.push_back(w); 
        dict.insert(w); 
      }
      return res;
    }
  
    // if word w is concatenatable by words from dictionary "dict"
    bool wordBreak(string& w) 
    {
        // check if w has a new char not in dict     
        if (charset.size() < 26) {          
          bool newChar = false;
          for(char c:w) 
            if(charset.insert(c).second) newChar = true;
          
          if (newChar) return false;
        }
              
        // DP to check if w is concatenatable
        vector<bool> dp(w.size()+1, false); // dp[L]: if w.substr(0,L) is concatenatable by dict 
        for (int L = minL; L <= w.size(); ++L) {
            if (dict.count(w.substr(0,L))) {
              dp[L] = true;
              continue;
            }
          
            for (int j = minL; j <= L-minL; ++j) {
              dp[L] = dp[L-j] && dict.count(w.substr(L-j, j));
              if (dp[L]) break;
            }
        }
        return dp.back();
    }
    
    vector<string> res;          // all concatenatable words
    unordered_set<string> dict;  // all previous words 
    unordered_set<char> charset; // char set of all previous words
    int minL; // min length of given words


// Dynamic Prog
// time limit exceeded my solution + link: https://leetcode.com/problems/concatenated-words/discuss/95715/C%2B%2B-DP-solution-with-unique-char-and-length-check-(detailed-explanation)
class Solution {
public:
    
    vector<string> dict;  // all previous words 
    unordered_set<char> charset; // char set of all previous words
    
    bool wordBreak(string A, vector<string>& B) {
        
        // check if w has a new char not in dict     
        if (charset.size() < 26) {          
          bool newChar = false;
          for(char c: A) 
            if(charset.insert(c).second) newChar = true;
          
          if (newChar) return false;
        }
        
        int N=A.size();
        int n=B.size();

        vector<bool> dp(N+1,0);
        dp[0]=1;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<n;j++)
            {
                int idx1=i;
                int idx2=B[j].size()-1;

                while(idx1>=0 && idx2>=0 && A[idx1]==B[j][idx2])
                    idx1--, idx2--;

                if(idx2==-1)
                    dp[i+1]=dp[idx1+1];
                if(dp[i+1])
                    break;
            }
        }

        return dp[N];
    }    

    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        if (words.empty() ) return {};
        
        vector<string> ans;
        
        // sort words by length
        sort(words.begin(), words.end(), [](string& s1, string& s2) { return s1.size() < s2.size(); });

        for (auto& w:words) {
            if (wordBreak(w,dict) && w.size()!=0) 
                ans.push_back(w);
            if ( find(dict.begin(), dict.end(), w) == dict.end() )
                dict.push_back(w); 
        }
        
        return ans;
    }
};