class Solution {
public:
    
    int par[('z'-'a'+1)];
    
    int find (int x){
        return (par[x]^x)?par[x] = find(par[x]) : x; 
    }
    
    bool do_union (int x,int y){
        int px,py;
        if( ( px = find(x)) == ( py = find(y) ) ){
            return 1;
        }
        par[px] = py;
        return 0;
    }
    
    bool is_union(int x,int y){
        int px,py;
        if( ( px = find(x)) == ( py = find(y) ) ){
            return 1;
        }
        return 0;
    }
    
    bool equationsPossible(vector<string>& equations) {
        for(int i=0; i< int('z'-'a'+1) ; ++i ){
            par[i] = i;
        }
        
        for( string s : equations ){
            if( s[1]=='=' ){
                do_union(s[0]-'a',s[3]-'a');
            }
            else if( s[1]=='!' && is_union(s[0]-'a',s[3]-'a' ) ) {
                return false;
            }
            
            // for(int i=0; i<26;++i){
            //     cout << par[i] << " ";
            // }
            // cout << "\n";
        }
        
        for( string s : equations ){
            if( s[1]=='!' ){
                if( is_union(s[0]-'a',s[3]-'a' )){
                    return false;
                }
            }
            
        }
        
        return true;
    }
};