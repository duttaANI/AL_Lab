#include <bits/stdc++.h>
using namespace std;
#define ar array


string s;

void solve(){
	
	cin >> s;

	int n = s.size(),c1=0,c2=0,ans=0;
	
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(') c1++;
		else if(s[i]=='[') c2++;
		else if(s[i]==')' && c1) c1--,ans++;
		else if(s[i]==']' && c2) c2--,ans++;
	}
	cout<<ans<<endl;
	return ;
}

int main(){
	int tt;
	cin >> tt;
	// string t;
	// getline(cin, t);
	while(tt--){
		solve();
	}
}
