class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        if(s == ""){
            return "";
        }
        
        int x = s.find(part);
        
        if(x > s.size()){//there is not remaining (part) in string s
            return s;
        }
        
        string left = s.substr(0,x);
        string right = s.substr(x + part.size());
        return removeOccurrences(left+right , part);
        
        
    }
};