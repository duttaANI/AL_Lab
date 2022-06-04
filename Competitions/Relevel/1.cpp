#include <bits/stdc++.h>
using namespace std;
#define ar array

bool cmp(ar<int,3>& x, ar<int,3>& y){
    if( y[2]<x[2] ) return 1;
    else if ( y[2] == x[2] && y[0]<x[0] ) return 1;
    else{
        return 0;
    }
}

void solve(){
    int k,a,b;
    cin >> k;
    vector <ar<int,3>> v; // gcd

    // int l=1 , r=k/2;

    // while( l<r ){
    //     int cur = __gcd();
    // }


    for(int i=2;i<=k;i+=2 ){ // make sure i is even
        if( k%i==0 ){
            ar<int,3> a = { i , k/i, __gcd(i,k/i) };
            
            v.push_back(a);

            // cout << a[0] << " " << a[1] << " " << a[2] << " debg \n";
        }
    }

    

    if( v.size()==0 ){
        cout << -1 << " " << -1 << endl;
        return;
    }
    sort(v.begin(),v.end(),cmp);
    //reverse(v.begin(),v.end());

    cout << v[0][0] << " " << v[0][1] << "\n";
}

int main() {
	// your code goes here
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
	return 0;
}

/*

A + B = K ( not true )

A * B = K = GCD(A,B) * LCM(A,B)

GCD (A,B) is max

A%2 == 0

B%2 == 1



f no values of A and B exist print “-1 -1” (without quotes). 

If there are multiple values of A and B, print the one with maximum A (even).

1<=T<=5*10^5

1<=K<=10^7

*/