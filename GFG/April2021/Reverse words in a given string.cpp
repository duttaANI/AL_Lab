class Solution{
  public:
    string reverseWords(string S) 
    { 
        // code here 
        stack<string> s;
        string temp = "";
        for( int i=0; i<S.size();  ){
            
            while( i<S.size() && S[i]!='.' ){
                temp += S[i];
                ++i;
            }
            s.push(temp);
            temp = "";
            ++i;
        }
        
        string ans = "";
        while( s.size() ){
            string t = s.top(); s.pop();
            ans += t;
            ans += ".";
        }
        
        ans.pop_back();
        
        return ans;
    } 
};