// // <<<<<<<<<<<<<<<<<<< Dijkstra + deleting edges is TLE >>>>>>>>>>>>>>>>>>>>>>>>>>>>
// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ar array

// int N,K,R;

// const int mxN = 1e5;
// int C[mxN];
// vector<ar<ll,2>> adj[mxN];
// ll minDist[mxN];

// // A utility function to delete an edge in an 
// // undirected graph. 
// void delEdge(vector<ar<ll,2>> adj[], int u, int v) 
// { 
//     // Traversing through the first vector list 
//     // and removing the second element from it 
//     int i=0;
//     for( ar<ll,2> v : adj[u] ){
//     	if( v[1]==u ){
//     		adj[u].erase(adj[u].begin()+i);
//     		break;
//     	}
//     	++i;
//     } 
  
//     // Traversing through the second vector list 
//     // and removing the first element from it 
//     i=0;
//     for (ar<ll,2> u : adj[v]) { 
//         if( u[1]==v ){
//     		adj[v].erase(adj[v].begin()+i);
//     		break;
//     	}
//     	++i; 
//     } 
// } 


// int main() {
// 	cin >> N >> K >> R;
// 	for (int i = 0; i < K; ++i)
// 	{
// 		cin >> C[i]; --C[i];
// 	}

// 	for (int i = 0,a,b; i < N-1; ++i)
// 	{
// 		cin >> a >> b; --a,--b;
// 		adj[a].push_back({1,b});
// 		adj[b].push_back({1,a});
// 	}

// 	set <int > SET;
// 	for (int i = 0; i < N; ++i)
// 	{
// 		SET.insert(i);
// 	}

//     set <int > :: iterator itr;  
//  //    for (itr = SET.begin(); itr != SET.end(); ++itr) 
//  //    { 
//  //        cout << *itr << " "; 
//  //    } 
//  //    cout << "\n"; 

// 	for (int i = 0; i < K; ++i) // Do BFS K times
// 	{
// 		memset(minDist,0x3f,sizeof(minDist));
		
// 		minDist[C[i]]=0; // distance from affected city

// 		priority_queue< ar<ll,2> , vector< ar<ll,2> > /*, greater< ar<ll,2> >*/ > pq;

// 		pq.push({0,C[i]});
		
	
// 		while( pq.size() ){
// 			ar<ll,2> u = pq.top();
// 			pq.pop();
// 			if( u[0]>minDist[u[1]] )
// 				continue;
// 			for( ar<ll,2> v : adj[u[1]] ){
// 				if( minDist[v[1]]> minDist[u[1]] + v[0] ){
// 					minDist[v[1]] = minDist[u[1]] + v[0];
// 					// cout << v[1] << " " << minDist[v[1]] << "\n";
// 					pq.push({minDist[v[1]], v[1]});
// 				}
// 			}
// 		}



// 		for (int x = 0; x < N; ++x)
// 		{
// 			// cout << minDist[x] << " ";
// 			if( minDist[x]>R ){
// 				SET.erase(x);
// 				delEdge(adj,i,x);
// 			}
// 		}
// 		// cout << "\n";

// 	}

// 	// for (itr = SET.begin(); itr != SET.end(); ++itr) 
//  //    { 
//  //        cout << *itr+1 << " "; 
//  //    } 

//  //    cout << "\n";

// 	if(SET.size()==0){
// 		cout << 0;
// 	}else{
// 		cout << SET.size();
// 	}


// 	return 0;
// }











































// <<<<<<<<<<<<<< BFS + deleting egdes is TLE >>>>>>>>>>>>>>>>>>>>>>>>>>
// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// int N,K,R;

// const int mxN = 1e5;
// int C[mxN];
// vector<int> adj[mxN];
// int minDist[mxN];
// int vis[mxN];



// // A utility function to delete an edge in an 
// // undirected graph. 
// void delEdge(vector<int> adj[], int u, int v) 
// { 
//     // Traversing through the first vector list 
//     // and removing the second element from it 
//     for (int i = 0; i < adj[u].size(); i++) { 
//         if (adj[u][i] == v) { 
//             adj[u].erase(adj[u].begin() + i); 
//             break; 
//         } 
//     } 
  
//     // Traversing through the second vector list 
//     // and removing the first element from it 
//     for (int i = 0; i < adj[v].size(); i++) { 
//         if (adj[v][i] == u) { 
//             adj[v].erase(adj[v].begin() + i); 
//             break; 
//         } 
//     } 
// } 


// int main() {
// 	cin >> N >> K >> R;
// 	for (int i = 0; i < K; ++i)
// 	{
// 		cin >> C[i]; --C[i];
// 	}
// 	for (int i = 0,a,b; i < N-1; ++i)
// 	{
// 		cin >> a >> b; --a,--b;
// 		adj[a].push_back(b);
// 		adj[b].push_back(a);
// 	}
// 	set <int > SET;
// 	for (int i = 0; i < N; ++i)
// 	{
// 		SET.insert(i);
// 	}

//     set <int, greater <int> > :: iterator itr;  
//  //    for (itr = SET.begin(); itr != SET.end(); ++itr) 
//  //    { 
//  //        cout << *itr << " "; 
//  //    } 
//  //    cout << "\n"; 

// 	for (int i = 0; i < K; ++i) // Do BFS K times
// 	{
// 		memset(minDist,0x3f,4*N);
// 		memset(vis,0,4*N);
// 		minDist[C[i]]=0; // distance from affected city
// 		queue<int> qu;
// 		qu.push(C[i]);
// 		while(qu.size()){
// 			int u = qu.front(); qu.pop();

// 			for ( int v : adj[u] ) // u -> parent, v -> child
// 			{
// 				if( vis[v]==0 ){
// 					vis[v] = 1;
// 					minDist[v] = minDist[u]+1;
// 					if(minDist[v]<R) // prunning
// 						qu.push(v);
// 					// else{ // remove edge
// 					// 	cout << " to delete : " << u << " " << v << "\n";
// 					// 	delEdge(adj,u,v);
// 					// }
					
					
// 				}
// 			}
// 		}
// 		minDist[C[i]]=0;
// 		for (int x = 0; x < N; ++x)
// 		{
// 			// cout << minDist[x] << " ";
// 			if( minDist[x]>R ){
// 				SET.erase(x);
// 				// remove edge
// 				// cout << " to delete : " << i << " " << x << "\n";
// 				delEdge(adj,i,x);
// 			}
// 		}
// 		// cout << "\n";
// 	}

// 	// for (itr = SET.begin(); itr != SET.end(); ++itr) 
//  //    { 
//  //        cout << *itr << " "; 
//  //    } 

// 	if(SET.size()==0){
// 		cout << 0;
// 	}else{
// 		cout << SET.size();
// 	}


// 	return 0;
// }













































// <<<<<<<< Below multisource BFS/Dijkstra does not work for this Q >>>>>>>>>>>>>>>>>>>
// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ar array

// int N,K,R;

// const int mxN = 1e5 + 1;
// int C[mxN];
// vector<ar<ll,2>> adj[mxN];
// ll minDist[mxN];


// int main() {
// 	cin >> N >> K >> R;
// 	for (int i = 0; i < K; ++i)
// 	{
// 		cin >> C[i]; --C[i];
// 	}
// 	for (int i = 0,a,b; i < N-1; ++i)
// 	{
// 		cin >> a >> b; --a,--b;
// 		adj[a].push_back({1,b});
// 		adj[b].push_back({1,a});
// 	}

// 	// connecting all affected nodes to a single new node
// 	for (int i = 0; i < K; ++i)
// 	{
// 		adj[(ll)1e5].push_back({1,C[i]});
// 		adj[C[i]].push_back({1,(ll)1e5});
// 	}
// 	set <int > SET;
// 	for (int i = 0; i < N; ++i)
// 	{
// 		SET.insert(i);
// 	}

//     set <int > :: iterator itr;  
//  //    for (itr = SET.begin(); itr != SET.end(); ++itr) 
//  //    { 
//  //        cout << *itr << " "; 
//  //    } 
//  //    cout << "\n"; 

	
// 	memset(minDist,0x3f,sizeof(minDist));
	
// 	minDist[(ll)1e5]=0; // distance from affected city

// 	priority_queue< ar<ll,2> , vector< ar<ll,2> > , greater< ar<ll,2> > > pq;

// 	pq.push({0,(ll)1e5});
	

// 	while( pq.size() ){
// 		ar<ll,2> u = pq.top();
// 		pq.pop();
// 		if( u[0]>minDist[u[1]] )
// 			continue;
// 		for( ar<ll,2> v : adj[u[1]] ){
// 			if( minDist[v[1]]> minDist[u[1]] + v[0] ){
// 				minDist[v[1]] = minDist[u[1]] + v[0];
// 				cout << v[1] << " " << minDist[v[1]] << "\n";
// 				pq.push({minDist[v[1]], v[1]});
// 			}
// 		}
// 	}



// 	for (int x = 0; x < N; ++x)
// 	{
// 		cout << minDist[x] << " ";
// 		if( minDist[x]>R ){
// 			SET.erase(x);
// 		}
// 	}
//     cout << minDist[(ll)1e5] << "\n";


// 	// for (itr = SET.begin(); itr != SET.end(); ++itr) 
//  //    { 
//  //        cout << *itr+1 << " "; 
//  //    } 

//  //    cout << "\n";

// 	if(SET.size()==0){
// 		cout << 0;
// 	}else{
// 		cout << SET.size();
// 	}


// 	return 0;
// }













































// <<<<<<<<<<<<<<<<<Below soln is wrong>>>>>>>>>>>>>>>>>>>>

// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// int N,K,R;

// const int mxN = 1e5;
// int C[mxN];
// vector<int> adj[mxN];
// int minDist[mxN];
// int vis[mxN];

// int main() {
// 	cin >> N >> K >> R;
// 	for (int i = 0; i < K; ++i)
// 	{
// 		cin >> C[i]; --C[i];
// 	}
// 	for (int i = 0,a,b; i < N-1; ++i)
// 	{
// 		cin >> a >> b; --a,--b;
// 		adj[a].push_back(b);
// 		adj[b].push_back(a);
// 	}
// 	set <int > SET;
// 	for (int i = 0; i < N; ++i)
// 	{
// 		SET.insert(i);
// 	}

//     set <int, greater <int> > :: iterator itr;  
//  //    for (itr = SET.begin(); itr != SET.end(); ++itr) 
//  //    { 
//  //        cout << *itr << " "; 
//  //    } 
//  //    cout << "\n"; 

// 	for (int i = 0; i < K; ++i) // Do BFS K times
// 	{
// 		memset(minDist,0x3f,4*N);
// 		memset(vis,0,4*N);
// 		minDist[C[i]]=0; // distance from affected city
// 		queue<int> qu;
// 		qu.push(C[i]);
// 		while(qu.size()){
// 			int u = qu.front(); qu.pop();

// 			for ( int v : adj[u] ) // u -> parent, v -> child
// 			{
// 				if( vis[v]==0 ){
// 					vis[v] = 1;
// 					minDist[v] = minDist[u]+1;
// 					if(minDist[v]<R && ( SET.find(v) != SET.end() ) )
// 						qu.push(v);
					
// 				}
// 			}
// 		}
// 		minDist[C[i]]=0;
// 		for (int x = 0; x < N; ++x)
// 		{
// 			// cout << minDist[x] << " ";
// 			if( minDist[x]>R ){
// 				SET.erase(x);
// 			}
// 		}
// 		// cout << "\n";
// 	}

// 	// for (itr = SET.begin(); itr != SET.end(); ++itr) 
//  //    { 
//  //        cout << *itr << " "; 
//  //    } 

// 	if(SET.size()==0){
// 		cout << 0;
// 	}else{
// 		cout << SET.size();
// 	}


// 	return 0;
// }











































// <<<<<<<<<<<< Below BFS is TLE >>>>>>>>>>>>>>>>>>>>>>>
// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// int N,K,R;

// const int mxN = 1e5;
// int C[mxN];
// vector<int> adj[mxN];
// int minDist[mxN];
// int vis[mxN];

// int main() {
// 	cin >> N >> K >> R;
// 	for (int i = 0; i < K; ++i)
// 	{
// 		cin >> C[i]; --C[i];
// 	}
// 	for (int i = 0,a,b; i < N-1; ++i)
// 	{
// 		cin >> a >> b; --a,--b;
// 		adj[a].push_back(b);
// 		adj[b].push_back(a);
// 	}
// 	set <int > SET;
// 	for (int i = 0; i < N; ++i)
// 	{
// 		SET.insert(i);
// 	}

//     set <int, greater <int> > :: iterator itr;  
//  //    for (itr = SET.begin(); itr != SET.end(); ++itr) 
//  //    { 
//  //        cout << *itr << " "; 
//  //    } 
//  //    cout << "\n"; 

// 	for (int i = 0; i < K; ++i) // Do BFS K times
// 	{
// 		memset(minDist,0x3f,4*N);
// 		memset(vis,0,4*N);
// 		minDist[C[i]]=0; // distance from affected city
// 		queue<int> qu;
// 		qu.push(C[i]);
// 		while(qu.size()){
// 			int u = qu.front(); qu.pop();

// 			for ( int v : adj[u] ) // u -> parent, v -> child
// 			{
// 				if( vis[v]==0 ){
// 					vis[v] = 1;
// 					minDist[v] = minDist[u]+1;
// 					if(minDist[v]<R) // prunning
// 						qu.push(v);
					
					
// 				}
// 			}
// 		}
// 		minDist[C[i]]=0;
// 		for (int x = 0; x < N; ++x)
// 		{
// 			// cout << minDist[x] << " ";
// 			if( minDist[x]>R ){
// 				SET.erase(x);
// 			}
// 		}
// 		// cout << "\n";
// 	}

// 	// for (itr = SET.begin(); itr != SET.end(); ++itr) 
//  //    { 
//  //        cout << *itr << " "; 
//  //    } 

// 	if(SET.size()==0){
// 		cout << 0;
// 	}else{
// 		cout << SET.size();
// 	}


// 	return 0;
// }











































// <<<<<<<<<<<<<<<<<<<<< Below Dijkstra is TLE >>>>>>>>>>>>>>>>>>>>>
// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ar array

// int N,K,R;

// const int mxN = 1e5;
// int C[mxN];
// vector<ar<ll,2>> adj[mxN];
// ll minDist[mxN];


// int main() {
// 	cin >> N >> K >> R;
// 	for (int i = 0; i < K; ++i)
// 	{
// 		cin >> C[i]; --C[i];
// 	}
// 	for (int i = 0,a,b; i < N-1; ++i)
// 	{
// 		cin >> a >> b; --a,--b;
// 		adj[a].push_back({1,b});
// 		adj[b].push_back({1,a});
// 	}
// 	set <int > SET;
// 	for (int i = 0; i < N; ++i)
// 	{
// 		SET.insert(i);
// 	}

//     set <int > :: iterator itr;  
//  //    for (itr = SET.begin(); itr != SET.end(); ++itr) 
//  //    { 
//  //        cout << *itr << " "; 
//  //    } 
//  //    cout << "\n"; 

// 	for (int i = 0; i < K; ++i) // Do BFS K times
// 	{
// 		memset(minDist,0x3f,sizeof(minDist));
		
// 		minDist[C[i]]=0; // distance from affected city

// 		priority_queue< ar<ll,2> , vector< ar<ll,2> > , greater< ar<ll,2> > > pq;

// 		pq.push({0,C[i]});
		
	
// 		while( pq.size() ){
// 			ar<ll,2> u = pq.top();
// 			pq.pop();
// 			if( u[0]>minDist[u[1]] )
// 				continue;
// 			for( ar<ll,2> v : adj[u[1]] ){
// 				if( minDist[v[1]]> minDist[u[1]] + v[0] ){
// 					minDist[v[1]] = minDist[u[1]] + v[0];
// 					// cout << v[1] << " " << minDist[v[1]] << "\n";
// 					pq.push({minDist[v[1]], v[1]});
// 				}
// 			}
// 		}



// 		for (int x = 0; x < N; ++x)
// 		{
// 			// cout << minDist[x] << " ";
// 			if( minDist[x]>R ){
// 				SET.erase(x);
// 			}
// 		}
// 		// cout << "\n";

// 	}

// 	// for (itr = SET.begin(); itr != SET.end(); ++itr) 
//  //    { 
//  //        cout << *itr+1 << " "; 
//  //    } 

//  //    cout << "\n";

// 	if(SET.size()==0){
// 		cout << 0;
// 	}else{
// 		cout << SET.size();
// 	}


// 	return 0;
// }












































// // <<<<<<<<<<<<<<<<<<<<<<<< Below BFS is TLE >>>>>>>>>>>>>>>>>>>>>>>>>>>>
// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// int N,K,R;

// const int mxN = 1e5;
// int C[mxN];
// vector<int> adj[mxN];
// int minDist[mxN];
// int vis[mxN];

// int main() {
// 	ios::sync_with_stdio(false);
//     cin.tie(0);
// 	cin >> N >> K >> R;
// 	for (int i = 0; i < K; ++i)
// 	{
// 		cin >> C[i]; --C[i];
// 	}
// 	for (int i = 0,a,b; i < N-1; ++i)
// 	{
// 		cin >> a >> b; --a,--b;
// 		adj[a].push_back(b);
// 		adj[b].push_back(a);
// 	}
// 	set <int > SET;
// 	for (int i = 0; i < N; ++i)
// 	{
// 		SET.insert(i);
// 	}

//     set <int, greater <int> > :: iterator itr;  
//  //    for (itr = SET.begin(); itr != SET.end(); ++itr) 
//  //    { 
//  //        cout << *itr << " "; 
//  //    } 
//  //    cout << "\n"; 

// 	for (int i = 0; i < K; ++i) // Do BFS K times
// 	{
// 		memset(minDist,0x3f,4*N);
// 		memset(vis,0,4*N);
// 		minDist[C[i]]=0; // distance from affected city
// 		queue<int> qu;
// 		qu.push(C[i]);
// 		while(qu.size()){
// 			int u = qu.front(); qu.pop();

// 			for ( int v : adj[u] ) // u -> parent, v -> child
// 			{
// 				if( vis[v]==0 ){
// 					vis[v] = 1;
// 					qu.push(v);
// 					minDist[v] = minDist[u]+1;
					
// 				}
// 			}
// 		}
// 		minDist[C[i]]=0;
// 		for (int x = 0; x < N; ++x)
// 		{
// 			// cout << minDist[x] << " ";
// 			if( minDist[x]>R ){
// 				SET.erase(x);
// 			}
// 		}
// 		// cout << "\n";
// 	}

// 	// for (itr = SET.begin(); itr != SET.end(); ++itr) 
//  //    { 
//  //        cout << *itr << " "; 
//  //    } 

// 	if(SET.size()==0){
// 		cout << 0;
// 	}else{
// 		cout << SET.size();
// 	}


// 	return 0;
// }
