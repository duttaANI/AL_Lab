class Solution {
public:
    int secondHighest(string s) {
        int mx1=-1 ,mx2=-1;
        for(  int i=0;i<s.size();++i ){
            if( isdigit(s[i])  ){
                if(s[i]-'0' > mx1){
                     mx2 = mx1;
                     mx1 = (int)(s[i]-'0');
                }
                else if(s[i]-'0' == mx1){
                    continue;
                }
                else if(s[i]-'0' > mx2){
                     mx2 = (int)(s[i]-'0');
                }
            }
        }
       
        return mx2;
    }
};