#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){

	string s;
	cin >> s;

	deque <int> dq;

	int n = s.length();

	for (int i = n-1; i >= 0; --i)
	{
		if(s[i]=='r'){
			dq.push_front(n);
		}else{
			dq.push_back(n);
		}
		--n;
	}

	deque <int> :: iterator it; 
    for (it = dq.begin(); it != dq.end(); ++it) 
        cout << *it << " "; 

	return 0;
}