class Solution {
public:
    int countLatticePoints(vector<vector<int>>& v) { // v is vector of circles.
        int n = v.size();
        int ans = 0;
        for(int x=0;x<=200;x++){
            for(int y=0;y<=200;y++){
                for(int i=0;i<n;i++){
                    int a=v[i][0],b=v[i][1],r=v[i][2];
                    if((a-x)*(a-x) + (b-y)*(b-y) <= r*r){
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
    // BELOW is TLE
//     #define ar array
//     int dX[4] = {0,1,0,-1};
//     int dY[4] = {1,0,-1,0};
//     map<ar<int,2> , int > g_mp; // visited for all circles ?
//     map<ar<int,2> , int > mp; // visited for specific circle?
//     int ans = 0;
    
    
//     bool inside_circle(int x1,int y1,int a,int b, int r){
//         if(  (x1-a)*(x1-a) + (y1-b)*(y1-b) - r*r <=0  ){
//             // cout << a << " <-a b-> " << b << endl;
//             return 1;
//         }
//         return 0;
//     }
    
//     void dfs(int x1,int y1,int a,int b,int r){
//         if( inside_circle(x1,y1,a,b,r) ){
            
//             if( g_mp.find({a,b})==g_mp.end() ){
//                 g_mp[{a,b}]++;
//                 ++ans;
//             }
            
//             if( mp.find({a,b})==mp.end() ){
//                 mp[{a,b}]++;
//                 for(int i=0;i<4;++i){
//                     int na = a + dX[i];
//                     int nb = b + dY[i];
//                     dfs(x1,y1,na,nb,r);
//                 }
//             }
//         }
//     }
    
//     bool is_inside_big_circle(int x1,int y1,int r){
        
//         // scaling r
//         r *= 2;
        
//         if( g_mp.find({x1,y1+r})!=g_mp.end() && 
//             g_mp.find({x1,y1-r})!=g_mp.end() && 
//             g_mp.find({x1+r,y1})!=g_mp.end() && 
//             g_mp.find({x1-r,y1})!=g_mp.end() &&
//             g_mp.find({x1-r,y1-r})!=g_mp.end() &&
//             g_mp.find({x1+r,y1+r})!=g_mp.end() &&
//             g_mp.find({x1-r,y1+r})!=g_mp.end() &&
//             g_mp.find({x1+r,y1-r})!=g_mp.end() 
//           ){
//             return 1;
//         }
//         return 0;
//     }
    
//     static bool cmp( vector<int> & a, vector<int> &b ){
//         if( a[2]>b[2] ) return 1;
//         return 0;
//     }
    
//     int countLatticePoints(vector<vector<int>>& c) {
        
//         sort(c.begin(),c.end(),cmp);
        
//         map < vector<int> , int> vis; // for repeating circles
        
//         int n = c.size();
        
        
//         for(int i=0;i<n;++i){
//             int x1 = c[i][0];
//             int y1 = c[i][1];
//             int r = c[i][2];
            
//             mp.clear(); 
//             if( vis.find({x1,y1,r})==vis.end() && !is_inside_big_circle(x1,y1,r) ){
//                 vis[ {x1,y1,r} ]++;
//                 dfs(x1,y1,x1,y1,r);
//             }
            
//         }
        
//         return ans;
//     }
};