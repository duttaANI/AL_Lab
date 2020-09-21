#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,m;


int find(int x,vector<int> &parent, int & i) //  x_idx address is passed (by reference)
{
    i = x;
    return parent[x]<0?parent[x]:find(parent[x],parent,i);
}

void find2(int x,vector<int> &parent) {
    while(parent[x]>0 && parent[x]<=n && parent[parent[x]]>0 && parent[parent[x]]<=n ){
    	parent[x] = parent[parent[x]];
    }
}

bool w_union(int x, int y, vector<int> &parent) {
    int x_idx;   // represents parent of x
    int xr = find(x,parent,x_idx);   // xr is rank of the parent x_idx
    
    int y_idx; // represents parent of y
    int yr = find(y,parent,y_idx);
    
    // perform weighted union
    if ( xr < yr ) {   // rank of x_idx is lesser implies that it has more children compared to y_idx
       
        parent[x_idx] = xr + yr;        // increasing magnitude ( ranks are -ve) of rank of x_idx since it's children incresed by amount "yr"
        parent[y_idx] = x_idx;         // collapsing path
     
    } else if ( yr < xr ) {
        parent[y_idx] = xr + yr;
        parent[x_idx] = y_idx;
    
    } else { // (xr == yr) 
        
        if (x_idx == y_idx){
            return false;
        } 
        else {
            parent[x_idx] = xr + yr;
            parent[y_idx] = x_idx;
        }
    }
    
    return true;
}

int main() {
	cin >> n >> m;
	vector<ll> money(n,0);
	for (int i = 0; i < n; ++i)
	{
		cin >> money[i];
	}
	vector<vector<int>> edges;
	vector<int> parent (n+1,-1); // if parent[i] < 0 => i is parent of itself
	for (int i = 0,a,b; i < m; ++i)
	{
		cin >> a >> b;
		edges.push_back({a,b});
	}

	for(auto &x:edges) {
        w_union(x[0], x[1], parent);
    }
   
    for (int i = 1; i < n+1; ++i)
    {
    	find2(i,parent);
    	
    }
    // for (int i = 1; i < n+1; ++i)
    // {
    // 	cout << parent[i] << " ";
    // }

    for (int i = 1; i < n+1; ++i)
    {
    	if(parent[i]<0){
    		parent[i] = i;
    	}
    }
    // for (int i = 1; i < n+1; ++i)
    // {
    // 	cout << parent[i] << " ";
    // }
    // cout << "\n";
    ll sum=0; 
    for (int i = 1; i < n+1; ++i)
    {
    	ll mn = 1e15;
    	for (int j = 1; j < n+1; ++j)
    	{
    		
    		if(parent[j]==i){
    			mn = min({mn,(ll)money[j-1]});
    			
    		}
    	}
    	if(mn!=1e15){
    		// cout << mn << "\n";
    		sum += mn;
    	}
    }

    cout << sum ;

	return 0;
}

/*
12 11
1 2 3 4 5 6 7 8 9 10 11 12
1 2
2 3
3 1
3 8
6 8
7 8
6 7
4 5
11 10
10 12
12 11

op- 
24

*/