class Solution {
public:
    string removeDigit(string number, char digit) {
        string cpy = number;
        int n = number.size();
        string ans = "0";
        for(int i=0;i<n;++i){
            if( number[i] == (digit) ){
                cpy.erase(i,1);
                // cout << cpy << endl;
                if( cpy > ans  ){
                    ans  = cpy;
                }
                cpy = number;
            }
        }
        return ans;
    }
};