class Solution {
public:
    
    int valid(string s){
        unordered_map <char,int> mp;
        for(int i=0;i<s.size();++i){
            mp[s[i]]++;
        }
        
        for(auto it : mp){
            if( it.first >= 'a' && it.first <= 'z' ){
                if( mp.find( char( it.first-32) )!=mp.end()  ){
                    continue;
                }
                else{
                    return 0;
                }
            }
            if( it.first >= 'A' && it.first <= 'Z' ){
                if( mp.find( char( it.first+32) )!=mp.end()  ){
                    continue;
                }
                else{
                    return 0;
                }
            }
        }
        
        return 1;
    }
    
    string longestNiceSubstring(string s) {
        string ans = "";
        for(int i=0;i<s.size();++i){
            for(int j=i+1;j<=s.size();++j){
                if( valid( s.substr(i,j-i) ) && s.substr(i,j-i).size()>ans.size() ){
                    ans = s.substr(i,j-i);
                }
            }
        }
        return ans;
    }
};