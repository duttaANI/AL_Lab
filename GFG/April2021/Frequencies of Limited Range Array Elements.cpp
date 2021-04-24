class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencycount(vector<int>& A,int n)
    { 
        // code here
        
        for (int i = 0; i < n; i++) {
            A[i] -= 1;
        }
        
        for (int i = 0; i < n; i++){
            A[A[i] % n] += n;
        }
     
        for (int i = 0; i < n; i++)
        {
            A[i] = A[i]/n;
        }
    }
};