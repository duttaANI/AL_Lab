#include <bits/stdc++.h>
using namespace std;


string multiple(int A) {
	if(A==1) return "1";
    vector<int> p(A,-1);
    vector<int> s(A,-1);

    queue <int> q;
    q.push(1);

    int steps[2] = {0,1};

    while(!q.empty()){
    	int curr = q.front();
    	q.pop();

    	for(int st : steps){
    		int m = (curr*10 + st)%A ;
    		if(p[m]==-1){
    			p[m] = curr;
    			s[m] = st;
    			q.push(m);
    		}

    	}
    }

    string ans ;

    for( int it=0; it!=1; it=p[it]){
    	ans.push_back('0'+s[it]);
    }
    ans.push_back('1');

    return string(ans.rbegin(), ans.rend());
}

int main(){
	cout << multiple(55);
}