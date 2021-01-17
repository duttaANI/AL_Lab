
// without remembering result of isPalindrome
class Solution {
public:
    
   void dfs(vector<vector<string>> &result, string &s, int start, vector<string>& curlist){
       if(start >= s.length()){
           result.push_back(curlist);
       }
       for( int end=start; end<s.length(); ++end ){
           if(isPalindrome(s,start,end)){
               curlist.push_back( s.substr(start,end-start+1 ) );
               dfs( result, s, end+1, curlist );
               curlist.pop_back();
           }
       }
   } 
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curlist; // this is like a stack
        dfs(result, s,0,curlist);
        return result;
    }
    
    bool isPalindrome(string &s, int low, int high) {
        while (low < high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }
};



// with remembering result of isPalindrome in a 2D boolean dp array [start][end]


class Solution {
public:
    
   void dfs(vector<vector<string>> &result, string &s, int start, vector<string>& curlist, vector<vector<bool>> & dp ){
       if(start >= s.length()){
           result.push_back(curlist);
       }
       for( int end=start; end<s.length(); ++end ){
           if( s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1]) ){
               dp[start][end] = true;
               curlist.push_back( s.substr(start,end-start+1 ) );
               dfs( result, s, end+1, curlist, dp );
               curlist.pop_back();
           }
       }
   } 
    
    vector<vector<string>> partition(string s) {
        int len = s.length();
        vector<vector<bool>> dp (len, vector <bool> (len, false));
        vector<vector<string>> result;
        vector<string> curlist; // this is like a stack
        dfs(result, s,0,curlist, dp);
        return result;
    }
    
    
};