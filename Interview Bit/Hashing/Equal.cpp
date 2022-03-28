vector<int> Solution::equal(vector<int> &A) {
    int n = A.size();
    vector<vector<int>> res;
    unordered_map<int, pair<int,int> > m; // two sum : indices
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(m[A[i] + A[j]] != make_pair(0, 0)){
                int A1 = m[A[i] + A[j]].first;
                int B1 = m[A[i] + A[j]].second;
                int C1 = i;
                int D1 = j;
                if(A1 > C1){
                    A1 = i;
                    B1 = j;
                    C1 = m[A[i] + A[j]].first;
                    D1 = m[A[i] + A[j]].second;
                }
                if(B1 == C1 || B1 == D1 || A1 == C1)continue;
                else {
                    vector<int> v = {A1, B1, C1, D1};
                    res.push_back(v);
                }
            }
            else{
                m[A[i] + A[j]] = {i, j};
            }
        }
    }
    sort(res.begin(), res.end());
    return res[0];
}