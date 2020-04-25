class Solution {
public:
    void backtrack(vector<string>& res, string& temp, int open, int close,  int n)
    {
        if(temp.length()==2*n)
        {
            res.push_back(temp);
            return ;
        }
        
        if(open<n)      
        {
            temp.push_back('(');  // IMP you cant use temp.push_back("(");
            backtrack(res,temp,open+1,close  ,n);
            temp.pop_back();
        }
        if(close<open)
        {
            //temp = temp + ")";  OR
            temp.push_back(')');  //This is faster than above
            backtrack(res,temp,open  ,close+1,n);
            temp.pop_back();
        }
    
    }
    
    vector<string> generateParenthesis(int n) {
        int open=0,close=0; // open -> number of open brackets
						 // close -> number of close brackets
        vector<string> res;
        if(n==0) return res;
        string temp="";
        backtrack(res,temp,open,close,n);
        return res;
    }
};