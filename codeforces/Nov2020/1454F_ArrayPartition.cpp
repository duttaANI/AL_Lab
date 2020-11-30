#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

int n;

struct node{
	ll mn,mx;
}st[1<<19];

void upd( int l1, int x, int i=1, int l2=0, int r2=n-1){ // similar to inserting in a binary search tree
	if(l2==r2){ // leaf node
		st[i].mn = x;
		st[i].mx = x;
		return ;
	}
	int m2 =(l2+r2)/2;
	if(l1<=m2){
		upd(l1,x,2*i,l2,m2);
	}
	else{
		upd(l1,x,2*i+1,m2+1,r2);
	}
	st[i].mn = min(st[2*i].mn,st[2*i+1].mn);
	st[i].mx = max(st[2*i].mx,st[2*i+1].mx);
}

int qry_min( int l1,int r1, int i=1, int l2=0, int r2=n-1){ // min on interval [l1,r1] , 0th indexing
	if(l1<=l2 && r2<=r1){
		return st[i].mn;
	}
	int m2 = (l2+r2)/2;
	return min( l1<=m2? qry_min(l1,r1,2*i,l2,m2):(int)1e9 , m2<r1? qry_min(l1,r1,2*i+1,m2+1,r2) : (int)1e9  );
}

int qry_max( int l1,int r1, int i=1, int l2=0, int r2=n-1){ // max on interval [l1,r1] , 0th indexing
	if(l1<=l2 && r2<=r1){
		return st[i].mx;
	}
	int m2 = (l2+r2)/2;
	return max( l1<=m2? qry_max(l1,r1,2*i,l2,m2):0 , m2<r1? qry_max(l1,r1,2*i+1,m2+1,r2) : 0  );
}

void solve(){
	cin >> n;
	
	vector<int> a(n);
	for(int i=0;i<n;++i){
		cin >> a[i], upd(i,a[i]);
	}

	int i;
    for(i = 0; i < n; i++)
    {
        int a, b, c;
        a = qry_max(0, i );
        int beg = i + 1, end = n - 2, mid;
        while(beg <= end)
        {
            mid = beg + end >> 1;
            b = qry_min( i + 1, mid );
            if(b == a)
            {
                c = qry_max( mid + 1, n-1);
                if(c == a)
                {
                    cout << "YES\n";
                    cout << i + 1 << ' ' << mid - i << ' ' << n - mid - 1 << '\n';
                    goto end;
                }
                else if(c < a)
                    end = mid - 1;
                else
                    beg = mid + 1;
            }
            else if( b < a)
                end = mid - 1;
            else
                beg = mid + 1;
        }
    }
    end:
    if(i == n)    cout << "NO\n";
}



int32_t main(){
	int tt;
	cin >> tt;
	while(tt--){
		solve();
	}

	return 0;
}

// void solve(){
// 	int n;
// 	cin >> n;
// 	vector<int> x(n),y(n),a(n),maxPlaces;
// 	for(int i=0;i<n;++i){
// 		cin >> a[i];
// 	}

// 	x[0] = a[0];
// 	for(int i=1;i<n;++i){
// 		x[i] = max({x[i],x[i-1]});
// 	}

// 	y[n-1] = a[n-1];
// 	for(int i=n-2;i>=0;--i){
// 		y[i] = max({y[i],y[i+1]});
// 	}

// 	int v = *max_element(a.begin(), a.end());
// 	for(int i=0;i<n;++i){
// 		if(a[i]==v)
// 			maxPlaces.push_back(i);
// 	}
// 	int lo = maxPlaces[maxPlaces.size()/2];
// 	int hi = lo+1;

// 	// BINARY SEARCH 
// 	while(true){
// 		if (lo == 0 || hi == n)
// 		{
// 			cout << "NO";
// 			break;
// 		}
// 		if (x[lo - 1] == v && y[hi] == v)
// 		{
// 			cout << "YES\n";
// 			cout << lo << " " << hi - lo << " " << n - hi ;
// 			break;
// 		}
// 		int u = (lo - 1 == 0) ? INT_MIN : min (x[lo - 2], a[lo - 1]);
// 		int w = (hi + 1 >= n) ? INT_MIN : min (y[hi + 1], a[hi]);
// 		if (u > w)
// 		{
// 			v = min (v, a[lo - 1]);
// 			lo -= 1;
// 		}
// 		else
// 		{
// 			v = min (v, a[hi]);
// 			hi += 1;
// 		}
// 	}

// 	cout << endl;
// }