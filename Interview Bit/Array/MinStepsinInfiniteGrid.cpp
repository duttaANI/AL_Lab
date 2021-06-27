int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int ans=0;
    int x = A[0];
    int y = B[0];
    for( int a=1; a<A.size(); ++a ){
        
        int m =  min( abs(x-A[a]),abs(y-B[a])  ) ; // add side of square
        ans += m;
        ans += max( abs(x-A[a]),abs(y-B[a])  )- m; // max side - min side
        x = A[a];
        y = B[a];
    }
    return ans;
}
