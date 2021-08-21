void Solution::setZeroes(vector<vector<int> > &A) {
    int H = A.size();
    int W = A[0].size();
    
    int isCol = 0;
    int isRow = 0;
    
    
    
    for(int i=0;i<H;++i){
        if( A[i][0]==0 ) isCol = 1;
    }
    for(int i=0;i<W;++i){
        if( A[0][i]==0 ) isRow = 1;
    }
    
    //
    
    
    for(int i=1;i<H;++i){
        for(int j=1;j<W;++j){
            if(  A[i][j]==0  ){
                // cout << i << " i   j " << j <<endl;
                A[0][j] = 0;
                A[i][0] = 0;
            }
        }
    }
    
    
    // set 0
    
    for(int i=1;i<H;++i){
        for(int j=1;j<W;++j){
            if( A[i][0]==0 || A[0][j]==0  ){
                A[i][j] =0;
            }
        }
    }
    
    
    
    
    // AT END
    
    if(isCol){
        for(int i=0;i<H;++i){
            A[i][0] = 0;
        }
    }
    if(isRow){
        for(int i=0;i<W;++i){
            A[0][i] = 0;
        }
    }
}
