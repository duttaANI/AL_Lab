bool Solution::hotel(vector<int> &arr, vector<int> &dep, int K) {
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int n = arr.size();
    bool ans = 1;
    int count = 0;
    int i=0,j=0;
    
    while(i<n && j<n){
        if(arr[i]<dep[j]){
            ++count;
            ++i;
        }
        else{
            --count;
            ++j;
        }
        if( count>K ){
            ans = 0;
            break;
        }
    }
    
    return ans;
}
