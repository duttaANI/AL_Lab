class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        
        if(word[0]<='Z' && word[0]>='A' ){
           if( word[1]<='Z' && word[1]>='A' )
           {
               for(int i=2; i<n; ++i){
                   if( word[i]<='Z' && word[i]>='A' ) continue;
                   return false;
               }
           }else if( word[1]<='z' && word[1]>='a' ){
               for(int i=2; i<n; ++i){
                   if( word[i]<='z' && word[i]>='a' ) continue;
                   return false;
               }
           }
           return true;
        }
        
        for(int i=0; i<n; ++i){
            if( word[i]<='z' && word[i]>='a' ) continue;
            return false;
        }
        return true;
    }
};