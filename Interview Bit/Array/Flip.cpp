vector<int> Solution::flip(string A) {
    
    int n = A.length();
    int cur_max=0,glo_max=INT_MIN,   beg=0,start=0,end=0;
    
    // idea -> make 0 to 1 , 1 to -1
    vector<int> a(n,0);
    for(int i=0; i<n; ++i){
        if(A[i]=='1'){
            a[i]=-1;
        }
        else{
            a[i]=1;
        }
    }
    // idea
    
    // Kadane
    for(int i=0; i<n; ++i){
        cur_max += a[i];
        if(cur_max<0){
            cur_max=0; // empty sub-array
            beg = i+1;
        }
        if( glo_max<cur_max ){
            glo_max=cur_max;
            start = beg;
            end = i;
        }
    }
    
    if(end<start){
        return {};
    }
    
    return {start+1,end+1};
}
