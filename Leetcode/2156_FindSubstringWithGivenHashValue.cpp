class Solution {
public:
    string subStrHash(string s, int p, int m, int k, int hashValue) {
        long long cur = 0, res = 0, pk = 1, n = s.size();
        
        for (int i = n - 1; i >= 0; --i) {
            cur = (cur*p + s[i]-'a'+1)%m;
            if(i+k>=n){
                pk = pk*p %m;
            }
            else{
                cur = ( cur - (s[i+k]-'a'+1)*pk%m +m  )%m;
            }
            if(cur==hashValue){
                res=i;
            }
        }
        return s.substr(res, k);
    }
};