class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        vector <int> stk; int n=ast.size();
        for (int i=0; i<n ;++i){
            if(stk.empty())
                stk.push_back(ast[i]);
            else if ( (stk[stk.size()-1]>0 && ast[i]>0) || (stk[stk.size()-1]<0 )  ){
                stk.push_back(ast[i]);
            } else {
                while( !stk.empty()  && (stk[stk.size()-1]>0 && ast[i]<0) && abs( stk[stk.size()-1] ) < abs( ast[i] )){
                    stk.pop_back();
                }
                if(  !stk.empty()  && (stk[stk.size()-1]>0 && ast[i]<0) && abs( stk[stk.size()-1] ) <= abs( ast[i] ) )                             
                    stk.pop_back();
                else if (!stk.empty()  && (stk[stk.size()-1]>0 && ast[i]<0) && abs( stk[stk.size()-1] ) > abs( ast[i] ))
                    continue;
                else
                    stk.push_back(ast[i]);
            }
        }
        return stk;
    }
};