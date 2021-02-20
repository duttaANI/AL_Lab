// DFS + memoization



int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool dfs(int i,int j,vector <string> &A,string &B,int pos,vector <vector <vector <int>>> &dp){
    if(pos==B.size())return 1;
    bool ans=(A[i][j]==B[pos]);
    if(dp[i][j][pos]!=-1)return dp[i][j][pos];
    if(ans==false)return dp[i][j][pos]=false;
    ans=false;
    for(int i2=0;i2<4;i2++){
        int ti,tj;
        ti=i+dx[i2];
        tj=j+dy[i2];
        if(ti>=0  && tj>=0 && ti<A.size() && tj<A[0].size()){
            ans=ans|dfs(ti,tj,A,B,pos+1,dp);
        }
    }
    return dp[i][j][pos]=ans;
}

int Solution::exist(vector<string> &A, string B) {
    bool ans=0;
    vector <vector <vector <int>>> dp(A.size(),vector <vector <int>> (A[0].size(),vector <int>(B.size(),-1)));
    if(B.size()==0)return 1;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(B[0]==A[i][j])
            ans=dfs(i,j,A,B,0,dp);
            if(ans){
                // cout<<i<<" "<<j<<"\n";
                return 1;}
        }
    }
    return ans;
}




// DFS 

bool isExist(int i, int j, int index, vector<string> &A, string B) {
    if(index == B.length())
        return true;
        
    int n = A.size();
    int m = A[0].size();
    
    if(i < 0 || j < 0 || i >= n || j >= m)
        return false;
    
    if(A[i][j] != B[index])
        return false;
    
    return isExist(i, j + 1, index+1, A, B) ||
           isExist(i, j - 1, index+1, A, B) ||
           isExist(i + 1, j, index+1, A, B) ||
           isExist(i - 1, j, index+1, A, B);
}

int Solution::exist(vector<string> &A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int b = B.length();
    if(b == 0) return 1;
        
    int n = A.size();
    if(n == 0) return 0;
    
    int m = A[0].size();
    if(m == 0) return 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j] == B[0]) {
                bool temp = isExist(i, j, 0, A, B);
                if(temp)
                    return 1;
            }
        }
    }
    
    return 0;
}


// My DFS gives TLE
#define ar array

int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};

int valid(int x, int y, int n, int m){
    if(x>=0 && y>=0 && x<n && y<m){
        return 1;
    }
    return 0;
}

void dfs(int x, int y, vector<string> &A, string B, int n , int m, int& l,int &ans){
    // cout << l << " x " << x << " y " << y << endl; 
    if(l-1==B.size()-1){
        ans=1;
        return ;
    }
    for(int i=0; i<4; ++i){
        int nx = x + dX[i];
        int ny = y + dY[i];
        if( valid(nx,ny,n,m) && A[nx][ny]==B[l] && l<=B.size()-1 ){
            dfs(nx,ny,A,B,n,m,++l,ans);
        }
    }
    --l;
}
int Solution::exist(vector<string> &A, string B) {
    int ans2=0;
    int n = A.size();
    int m = A[0].size();
    int l=0,ans=0;

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            l=0; ans=0;
            if(A[i][j]==B[l]){
                // cout << "hi : " << endl;
                dfs(i,j,A,B,n,m,++l,ans);
                
                if(ans){
                    ans2=1;
                }
            }
        }
    }
    return ans2;
}









/*
ABBDFDEBDE 
BEECFBFECC 
EDGEEGEFAD 
FFBBGFEECD 
GCGCEDECCF 
BFADBAEFEF
AEABBEDFAA 
EDFEBFCABG


DFBCDC
*/