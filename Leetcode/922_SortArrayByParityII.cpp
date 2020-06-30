class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int j=1;
        for (int i=0; i<A.size(); i+=2) {
            if(A[i]%2==1) { // increment i till odd encountered
                while(A[j]%2==1) // increment j till odd encountered
                    j+=2;
                
                // Swap A[i] and A[j]
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
        return A;
    }
};