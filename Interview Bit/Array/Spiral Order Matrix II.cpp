vector<vector<int> > Solution::generateMatrix(int a) {
    vector<vector<int>>ans(a,vector<int>(a,0));

    int mnr=0,mnc=0,mxr=a-1,mxc=a-1;
    int c = 0;
    while(c<a*a){
        //top
        for(int i=mnr, j=mnc;j<=mxc;j++){
            c++;
            ans[i][j]=c;
        }
        mnr++;
        //right
        for(int i=mnr, j=mxc;i<=mxr;i++){
            c++;
            ans[i][j]=c;
        }
        mxc--;
        //bottom
        for(int i=mxr, j=mxc;j>=mnc;j--){
            c++;
            ans[i][j]=c;
        }
        mxr--;
        //left
        for(int i=mxr, j=mnc;i>=mnr;i--){
            c++;
            ans[i][j]=c;
        }
        mnc++;
    }
    return ans;
}