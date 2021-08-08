#include <bits/stdc++.h>

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int n = s.size();
        int l=0, len  = 0,i=0;
        string temp;
        while( l+len <= n && i<words.size() ){
            if(  (temp = s.substr(l,len))  == (string)words[i] ){
                // cout << s.substr(l,len) << " <-substr l-> " << l << " len->  " << len << "\n";
                l += len;
                len = 0;
                ++i;
            }else{
                ++len;
            }
        }
        
        if( l==n ){
            return 1;
        }
        else{
            return 0;
        }
    }
};



//         int n = s.size();
//         unordered_map<string,int> mp;
//         for( auto i : words  ){
//             mp[i]++;
//         }
//         int l=0, len  = 0;
        
//         while( l+len <= n  ){
//             if( mp.find( s.substr(l,len) ) != mp.end()  ){
//                 cout << s.substr(l,len) << " <-substr l-> " << l << " len->  " << len << "\n";
//                 l += len;
//                 len = 0;
//             }else{
//                 ++len;
//             }
//         }
        
//         if( l==n ){
//             return 1;
//         }
//         else{
//             return 0;
//         }