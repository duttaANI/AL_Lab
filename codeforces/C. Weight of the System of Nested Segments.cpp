#include <bits/stdc++.h>
using namespace std;

#define ar array

bool cmp( ar<int,2>& a,ar<int,2>& b ){
    if(a[1]<b[1]) return 1;
    return 0;
}

void solve(){
    int n,m;
    cin >> n >> m;
    map<int,int> mp;
    vector<ar<int,2>> p;
    for(int i=0;i<m;++i){
        int x,w;
        cin >> x >> w;
        p.push_back({w,x});
        mp[x]=i;
    }
    sort(p.begin(),p.end());

    // for(auto i: p){
    //     cout << i[0] << "<->" << i[1] << " ";
    // }cout <<"\n";

    int sum = 0;
    for(int i=0;i<2*n;++i){
        sum += p[i][0];
    }
    sort(p.begin(),p.begin()+2*n,cmp);
    // for(auto i: p){
    //     cout << i[0] << "<->" << i[1] << " ";
    // }cout <<"\n";
    cout << sum << "\n";
    for(int i=0;i<n;++i){
        cout << mp[p[i][1]]+1 << " " << mp[p[2*n-i-1][1]]+1 << "\n";
    }
}

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
}