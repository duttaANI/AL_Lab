class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        
        int n= A.size();
        int sum, carry=0;
        
        for (int i=n-1; i>=0; --i) {
            
            sum = A[i] + K%10 + carry;
            A[i] = sum%10;
            carry = sum/10;
            
            K = K/10;
        } 
        
        while(K > 0) {
            sum = K%10 + carry;
            auto it = A.insert(A.begin(), sum%10);
            carry = sum/10;
            K = K/10;
        }
        
        if(carry>0 && K==0)
        auto it = A.insert(A.begin(), carry);
        
        return A;
    }
};