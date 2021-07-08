#define ar array

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    vector<int> ans;
    int n = A.size();
    deque<ar<int,2>> dq;
    
    // first 
    for(int i=0;i<n;++i){
        if(  dq.size() && dq.front()[1]  == i-B) dq.pop_front();
        while (!dq.empty() && dq.back()[0] < A[i])   dq.pop_back();  
        dq.push_back({A[i], i});
        if (i-B+1 >= 0) ans.push_back(dq.front()[0]);
    }
    
   
    
    return ans;
}