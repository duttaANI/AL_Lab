#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
 
typedef long long int lli;
typedef unsigned long int uli;
typedef pair<int,int> pi;
typedef pair<lli,lli> plli;
typedef vector<int> vi;
#define mod 1000000007
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define point(n) fixed<<setprecision(n)
#define endl "\n"
#define mem(a,val) memset(a,val,sizeof(a))
#define pb push_back
#define forn(i, a, n) for (int i = a; i < int(n); ++i)
#define inf 1e18
#define N int(2*1e5+10)
#define all(v) v.begin(),v.end()
#define pbds tree<pi, null_type,less<pi>, rb_tree_tag,tree_order_statistics_node_update> 
mt19937 rnd(time(NULL));
 
void printArr(vector<int> v){
    for(auto i:v)
        cout<<i<<" ";
}
unordered_map<string, int> mp;

vector<pair<int,int>> swappable_nodes{{0,1},{0,3},{3,4},{3,6},{6,7},{1,2},{1,4},{4,5},{4,7},{7,8},{2,5},{5,8}};

bool isPrime(int n){
    return (n==3 || n==5 || n==7 || n==11 || n==13 || n==17);
}
void solve(string s){
    queue<string> q;
    q.push(s);
    q.push("-1");
    int level=0;
    mp[s]=level;
    level++;
    while(!q.empty()){
        string curr = q.front();
        q.pop();
        if(curr=="-1"){
            if(!q.empty()){
                q.push("-1");
            }
            level++;
        } else{
            for(int i=0;i<swappable_nodes.size();i++){
                int vi = swappable_nodes[i].first;
                int vj = swappable_nodes[i].second;
                if(isPrime((curr[vi]-'0')+(curr[vj]-'0'))){
                    string str2(curr);
                    swap(str2[vi],str2[vj]);
                    if(mp.find(str2)==mp.end()){
                        mp[str2]=level;
                        q.push(str2);
                    }
                }
            }
        }
        
    }
}
int main(){
    fastIO;
    int t=1;
    string initial = "123456789";
    solve(initial);
    //for(auto i: mp){
      //  cout<<i.first<<" "<<i.second<<endl;
    //}
    cin>>t;
    while(t--){
        string final = "";
        for(int i=0;i<9;i++){
            int a;
            cin>>a;
            final+=to_string(a);
        }
        if(mp.find(final)!=mp.end()){
            cout<<mp[final];
        } else{
            cout<<-1;
        }
        cout<<endl;
    }
    return 0;
}