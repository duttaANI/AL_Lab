static const int mxN= 6e4+100;
#define ar array
static bool cmp(ar<int,3>& a , ar<int,3>& b){
    return a[2]<b[2];
}

    
int find(int x, int p[]){
    return (p[x]^x)?p[x]=find(p[x],p):x;
}

int join(int x, int y, int p[]){
    if( (x=find(x,p) ) == (y=find(y,p) )  ){
        return 0;
    }
    p[x] = y;
    return 1;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    int ans = 0;
        int p[mxN];
        vector<ar<int,3>> e;
        for(auto b : B){
            e.push_back({--b[0],--b[1],b[2]});
        }
        
        int n = e.size();
        
        // cout << n << endl;
        
        sort(e.begin(),e.end(),cmp);
        
        for(int i=0;i<A;++i){
            p[i] = i;
        }
        
        for(int i=0; i<n;++i){
            
            if(join(e[i][0],e[i][1],p)){
                ans += e[i][2];
            }
        } 
        
        return ans;
}
