// <3 Appy!
#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long ull;
typedef long long int ll;
typedef vector<long long int> vi;
int p[222222];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll n, sum = 0, count = 0, m, flag = 0, k;
    cin>>n>>k;
    vector<pair<int,int> > v, ans;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        v.push_back({x,i+1});
    }
    int i = 0, j = 1;
    sort(v.begin(),v.end());
    if(v[0].first != 0)
    {
        cout<<-1;
        return 0;
    }
    while(i<n && j<n)
    {
        if(v[i].first == v[j].first - 1 && p[v[i].second] < k && p[v[j].second] < k)
            ans.push_back({v[i].second,v[j].second}), p[v[j].second]++, p[v[i].second]++, j++, count++;
        else if(v[i].first == v[j].first)
        {
            cout<<-1;
            return 0;
        }
        else i++;
    }
    cout<<count<<endl;
    for(int i = 0; i < ans.size(); i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// #define ar array

// vector< ar<int,2> > e;

// unordered_map<int, vector<int> > mp;

// int main(){
// 	int n , k, root;
// 	cin >> n >> k;
// 	vector<int> d (n,0),vis(n,0);
// 	for(int i=0;i<n;++i){
// 		cin >> d[i];
// 		if(d[i]==0){
// 			root = i;
// 		}
// 		mp[d[i]].push_back(i);
// 	}

// 	if (  (mp.find(0)==mp.end()) ){
// 		cout << -1;
// 		return 0;
// 	}

// 	if(mp[0].size()!=1  ){
// 		cout << -1;
// 		return 0;
// 	}
// 	queue<ar<int,2>> q;
// 	q.push({root,0});
// 	vis[root] = 1;

// 	while(!q.empty()){
// 		ar<int,2> f = q.front(); q.pop();
// 		int cnt = 0;
// 		if(mp[f[1]+1].size()>k*(mp[f[1]].size()) ){
// 			cout << -1 ;
// 			return 0;
// 		}

// 		for(int i : mp[f[1]+1] ){
			
// 			if(!vis[i] && cnt<(k-1) /*because f[0] kisi ka child hai isiliye toh queue mein aya hain*/ ){ 
// 				cout << i+1 << " " << f[0]+1 << " " << cnt << endl;
// 				e.push_back({f[0],i});
// 				q.push({i,d[i]});
// 				vis[i] = 1;
// 				++cnt;
// 			}
// 		}
// 	}

// 	// are all nodes visited??
// 	int flag=1;
// 	for(int i=0;i<n;++i){
// 		if(vis[i]==0){
// 			flag = 0;
// 		}
// 	}

// 	if(e.size()!=0 && flag){
// 		cout << e.size() << endl;
// 		for( auto a : e ){
// 			cout << a[0]+1 << " " << a[1]+1 << endl;
// 		}
// 	}
// 	else{
// 		cout << -1 << endl;
// 	}

// 	return 0;
// }