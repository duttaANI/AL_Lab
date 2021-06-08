vector<int> Solution::grayCode(int A) {
    vector<int> ans;
    long long int x = 1<<A,i,j;
    for( i=0;i<x;++i){
        j = i/2;
        ans.push_back(i^j);
    }
    
    return ans;
}
