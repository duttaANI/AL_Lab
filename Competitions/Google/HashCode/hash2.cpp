#include<bits/stdc++.h>
#define ar array
using namespace std;
const int mxN = 1e7;
vector< ar<int,2> > adj[mxN],Radj[mxN];
	unordered_map<int,int> cars_AT_V;//vertex,count
	unordered_map<string,ar <int,3>> streets;
	unordered_map<string, string > Rstreets;
 
int main(){
	
	//input
	int P,D,I,S,V,F,B,E,T;
	cin >> D >> I >> S >> V >> F;
	while(S--){
	    string street_name;
	    cin>>B>>E;
	    cin>>street_name>>T;    
	    streets[street_name]={T,B,E};
	    adj[B].push_back({E,T}); // B -> start , E -> end
	    Radj[E].push_back({B,T});

	    string key = std::to_string(B) + " " + std::to_string(E);
	    Rstreets[key] = street_name;
	}

    // cout << "\n graph passed\n";

	vector<vector<int>> path;
	for(int j=0;j<V;j++){
		cin>>P;
		string s;
		int i=0;
		vector<int> vec(P,0); 
		while(P--){
			cin>>s;
			vec[i++]=streets[s][2];
		}
		cars_AT_V[vec[0]]++;
		path.push_back(vec);
	}

	// cout << "\n car path passed \n";

  	//code here

  	// out put 
	cout << I << "\n";
	for(int i=0; i<I; ++i){
		cout << i << "\n";
		cout << Radj[i].size() << "\n";
		for( ar<int,2> v : Radj[i] ){
			
			string key = std::to_string(v[0]) + " " + to_string(i);
			cout << Rstreets[key] << " " << 1 << "\n";
		}
	}

	// cout << "\n Yayy ";

	return 0;
  
}

	