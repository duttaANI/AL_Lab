class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> stk;
        
        int n = x.size();
        
        for(int i=0;i<n;++i){
            if( x[i]=='{' || x[i]=='[' || x[i]=='(' ){
                stk.push(x[i]);
            }
            else if( x[i]=='}' && !stk.empty() && stk.top()=='{' ){
                stk.pop();
            }
            else if( x[i]==']' && !stk.empty() && stk.top()=='[' ){
                stk.pop();
            }
            else if( x[i]==')' && !stk.empty() && stk.top()=='(' ){
                stk.pop();
            }
            else{
                return 0;
            }
        }
        
        return stk.empty();
    }

};