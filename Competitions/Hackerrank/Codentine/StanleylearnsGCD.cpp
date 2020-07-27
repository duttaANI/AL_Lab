#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  

} 

int LCM(int a, int b){ 
    return a*b/gcd(a,b);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<int> A (2000,0);
    vector<int> B (2000,0);
    int T,i,N,j,num;
    cin >> T;
    for(i=0; i<T; ++i){
        cin >> N;
        for(j=0;j<N;++j){
            cin >> num;
            A[j] = num;
        }
        B[0] = A[0];
        for(j=1;j<N;j++){
            B[j] = LCM(A[j],A[j-1]);
        }
        B[N] = A[N-1];
        for(j=0;j<N+1;++j){
            cout << B[j] << " ";
        }
        cout << "\n";
    }
  
    return 0;
}
