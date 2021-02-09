class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size(); int ans = n+1;
        deque<int> d;
        for(int i=0; i<n; ++i){
            if(i!=0){
                A[i]+=A[i-1];
            }
            if(A[i]>=K){
                ans = min({ ans, i+1 });
            }
            
            while( d.size() > 0 && A[i]-A[d.front()] >= K ){
                ans = min({ans, i-d.front() });
                d.pop_front();
            }
            while( d.size() > 0 && A[i]<= A[d.back()] ){
                d.pop_back();
            }
            
            d.push_back(i);
        }
        return (ans!=n+1)?ans:-1;
    }
};