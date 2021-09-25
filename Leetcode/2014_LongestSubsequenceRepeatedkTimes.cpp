class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        string res = "";
        queue<string> q;
        set <string> ss;
        q.push(res);
        ss.insert(res);
        
        while(q.size()){
            string f = q.front(); q.pop();
            for( char c = 'a'; c<='z'; c++  ){
                string y = f + c;
                string tmp = y.substr(1);
                if(  ss.find(tmp)==ss.end() ) {
                    continue;
                }
                
                int j=0;  int rep=0;
                for(int i=0;i<s.size() && rep < k;++i){
                    if(  s[i]==y[j] ){
                        ++j;
                        if(j==y.size()){
                            j=0;
                            rep++;
                        }
                    }     
                }
                
                if(  rep==k ){
                    res  = y;
                    q.push(y);
                    ss.insert(y);
                }
            }
        }
        
        return res;
    }
};