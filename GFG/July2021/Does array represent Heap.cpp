class Solution{
    public:
    bool isMaxHeap(int a[], int n)
    {
        // Your code goes here
        bool ans = 1;
        int i=0;
        for(int i=0; 2*i + 1 <= n ; ++i  ){
            if( a[2*i + 1] > a[i] ){
                ans = 0;
                break;
            }
            if( a[2*i + 2] > a[i] ){
                ans = 0;
                break;
            }
        }
        
        return ans;
    }
};
