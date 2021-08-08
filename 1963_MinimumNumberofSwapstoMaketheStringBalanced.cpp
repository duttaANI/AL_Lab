class Solution {
public:
    int minSwaps(string s) {
        int n=s.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]=='[')
                st.push('[');
            else{
            if(!st.empty() && s[i]==']' && st.top()=='[')
                st.pop();
            else
                st.push(']');
            }
        }
        int brackets=st.size()/2;
        if(brackets%2==0)return brackets/2;
        return (brackets/2)+1;

    }
};