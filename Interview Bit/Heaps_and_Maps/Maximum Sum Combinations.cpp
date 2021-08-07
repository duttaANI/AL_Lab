bool rev(int &a, int &b){
    return b<a;
}

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    priority_queue<int,vector<int>,greater<int> > pq;
    int n=A.size();
    sort(A.begin(),A.end(),rev);
    sort(B.begin(),B.end(),rev);
    for(int i=0;i<C;i++){
        pq.push(A[i]+B[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                if((A[i]+A[j])>=pq.top()){
                    pq.pop();
                    pq.push(A[i]+A[j]);
                }
                else{
                    break;
                }
            }
        }
    }
    vector<int> v;
    for(int i=0;i<C;i++){
        v.push_back(pq.top());
        pq.pop();
    }
    sort(v.begin(),v.end(),rev);
    return v;
}