vector<int> Solution::maxone(vector<int> &A, int B) {
    int len = A.size();
    int st =0, en = 0;
    int zcnt=0;
    for(  int i=0,j=0; j<len; ){
        // cout << i << " i  j " << j << endl;
        if( zcnt<=B  ){
            if( !A[j] ){
                
                ++zcnt;
            }
            ++j;
        }
        if( zcnt>B ){
            if( !A[i] ){
                
                --zcnt;
            }
            ++i;
        }
        
        if(  en-st < j-i  ){
            st = i;
            en = j;
        }
    }
    
    vector<int> ans;
    while(  st<en ){
        ans.push_back(st++);
    }
    
    return ans;
}
