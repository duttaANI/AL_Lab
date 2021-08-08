class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        string ans = "";
        int cnt = 0;
        for(int i=0;i<n-1;++i){
            
            if( s[i]==s[i+1]){
                ++cnt;
            }
            else{
                cnt=0;
            }
            
            if( cnt >= 2  ){
                continue;
            }
            ans += s[i];
        }
        ans += s[n-1];
        return ans;
    }
};