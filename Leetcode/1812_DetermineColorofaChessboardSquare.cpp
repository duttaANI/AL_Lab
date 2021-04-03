class Solution {
public:
    bool squareIsWhite(string c) {
        if( ( (c[0]-'a') + (c[1]-'0') )%2 ==0  ){
            return 1;
        }
        return 0;
    }
};