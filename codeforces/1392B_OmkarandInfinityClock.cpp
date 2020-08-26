#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    
    int mx = *max_element(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
      a[i] = mx - a[i];
    }
    mx = *max_element(a.begin(), a.end());
    if( k%2==0 )
    for (int i = 0; i < n; i++) {
      a[i] = mx - a[i];
    }
    
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << a[i];
    }
    cout << '\n';
  }
  return 0;
}



// Below doesnt work
// #include <bits/stdc++.h>
// using namespace std;

// #define test            int T_T; cin>>T_T; while(T_T--)
// #define fast_io         ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


// signed main()
// {
//     fast_io
//     int t;
//     cin >> t;
//     for(int i=0; i<t; ++i)
//    	{
//    			int n,k;
//    			cin >> n >> k;
//    			long long int Arr[n-1] ;
//             for (unsigned i = 0; i < n; i++)
//             {
//                 cin >> Arr[i];
//             }
            
            
//             long long int Max = *max_element(Arr,Arr+n);

// 			for (unsigned i = 0; i < n; ++i)
// 			{
// 				Arr[i] = Max - Arr[i];
// 			}

// 			Max = *max_element(Arr,Arr+n);
// 			if( k%2==0 ){
// 				for (unsigned i = 0; i < n; ++i)
// 				{
// 					Arr[i] = Max - Arr[i];
// 					cout << Arr[i] << " ";
// 				}
// 			}else{
// 				for (unsigned i = 0; i < n; ++i)
// 				{
// 					cout << Arr[i] << " ";
// 				}
// 			}
// 			if(t>0)
// 			cout << "\n";
//    	}
//     return 0;       
// }

