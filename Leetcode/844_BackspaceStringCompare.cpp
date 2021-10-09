class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1 = "",t1="";
        int n = s.size();
        for(int i=0;i<n;++i){
            if( s[i]=='#' ){
                if(s1.size())
                s1.pop_back();
            }
            else{
                s1.push_back(s[i]);
            }
        }
        n = t.size();
        for(int i=0;i<n;++i){
            if( t[i]=='#' ){
                if(t1.size())
                t1.pop_back();
            }
            else{
                t1.push_back(t[i]);
            }
        }
        
        // cout << s1 << " " << t1 << endl;
         
        return s1==t1;
    }
};