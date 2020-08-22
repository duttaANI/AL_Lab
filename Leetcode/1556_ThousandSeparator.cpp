class Solution {
public:
    string thousandSeparator(int n) {
       
        string stri = to_string(n);int count =0;
        
        reverse(stri.begin(), stri.end());
        
        for(int i=0; i<stri.length(); ++i){
            if(count==3 ){
                stri.insert(i, ".");
                count = 0;
            } 
            else
                ++count;
        }
        
        reverse(stri.begin(), stri.end());
        
        return stri;
    }
};