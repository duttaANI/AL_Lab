#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mxN = 1e5;
int h[mxN];
int minh[mxN];
int ans[mxN];
int ansIdx[mxN];
int n,m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin >> n ;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> h[i];
    }
    minh[n - 1] = h[n - 1];
    int mini = INT_MAX;
	for (int i = n - 1; i >= 0; i--){
        mini = min({ mini,h[i] });
        minh[i] = mini;
    }

    // for (int i = 0; i < n; ++i)
    // {
    //     cout << minh[i] << " ";
    // }
    // cout << "\n";

    ans[n-1] = -1;
    for( int i = n - 2; i >= 0; i-- ){
        int left = i; // after the binary search-> h[left] would be the answer
        int right = n - 1;
        while (left < right) {
            int mid = left + (right - left +1) / 2;
            if (minh[mid] < h[i])
                left = mid;
            else
                right = mid - 1;
            
        }
        if (minh[left] < h[i]){
            ans[i] = minh[left];
            ansIdx[i] = left-i-1; // max(left-i-1,0);
        }
        else
            ans[i] = -1;
    }

    // for (int i = 0; i < n; ++i)
    // {
    //     cout << ans[i] << " ";
    // }
    // cout << "\n";

    for (int i = 0; i < n; ++i)
    {
        if(ans[i]==-1){
            ansIdx[i] = -1;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cout << ansIdx[i] << " ";
    }

	return 0;
}

