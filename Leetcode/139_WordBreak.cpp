//link :https://leetcode.com/problems/word-break/discuss/43814/C%2B%2B-Dynamic-Programming-simple-and-fast-solution-(4ms)-with-optimization
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size()==0) return false;
        
        set<string> dict;
        for(auto w: wordDict)
            dict.insert(w);
        
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(dict.find(word)!= dict.end())
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }
        
        return dp[s.size()];
    }
};


// My approach 
/* fails for input:
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
*/
class Solution {
public:
    
    void dfs (string s, const vector<string>& wordDict, int start,int len, vector<bool>& dp) {
        if (dp[s.size()-1]==true) return;
        string word = s.substr(start,len);
        if( find(wordDict.begin(), wordDict.end(), word)!= wordDict.end())
        {
            dp[start+len-1]=true;
            if(len+start-1 < s.size() ) {
                
                //cout << len+start << " " << 1 << "\n";
                dfs(s, wordDict, len+start, 1, dp);
                
            }
        }
        if(start+len-1 < s.size()) {
            
            //cout << start << " " << len+1 << "out\n";
            dfs(s, wordDict, start, len+1, dp);
            
        }
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        vector<bool> dp (s.size(),false);
        
        dfs(s, wordDict, 0, 1, dp);
        
        // for (auto i : dp) {
        //     cout << i << " ";
        // }
        
        return dp[s.size()-1];
    }
};
