// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends

class Solution
{
public:
    int setKthBit(int N, int K)
    {
        // Write Your Code here
       
        string n ="";
        int cpy = N;
        while( cpy>0 ){
            int d = cpy%2;
            n += to_string(d);
            cpy /=2;
        }
        // reverse(n.begin(),n.end());
        // cout << n << " n1 \n";
        
        if(n[K]=='0'){
            n[K]='1';
        }
        
        // cout << n << " n2 \n";
        
        // reverse(n.begin(),n.end());
        
        // cout << n << " n3 \n";
        
        int ans = 0;
        for(int i=0;i<n.size();++i){
            if( n[i]=='1' ){
                ans += pow(2,i);
            }
        }
        return ans;
    }
    
};




// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        
        Solution ob;
        int ans = ob.setKthBit(N,K);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends