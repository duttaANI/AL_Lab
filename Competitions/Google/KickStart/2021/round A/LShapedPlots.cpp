#include <bits/stdc++.h>
using namespace std;

int u[1000][1000],d[1000][1000],l[1000][1000],r[1000][1000],in[1000][1000];

void solve(int cs){
	int R,C,ans=0;
	cin >> R >> C;
	// memset(u,0,sizeof(u));
	for(int i=0;i<R;++i){
		for(int j=0;j<C;++j){
			cin >> in[i][j];
			u[i][j] = in[i][j];
			d[i][j] = in[i][j];
			l[i][j] = in[i][j];
			r[i][j] = in[i][j];
		}
	}

	// d -> how many consequtive cells below
	for(int j = 0; j<C; ++j){
		for( int i = R-2; i>=0; --i){
			if(d[i][j])
				d[i][j] += d[i+1][j];
			else{
				d[i][j] = 0;
			}
		}
	}

	// u -> how many consequtive cells above
	for(int j = 0; j<C; ++j){
		for( int i = 1; i<R; ++i){
			if(u[i][j])
				u[i][j] += u[i-1][j];
			else{
				u[i][j] = 0;
			}
		}
	}

	// l -> how many consequtive cells to left
	for(int i=0; i<R; ++i){
		for(int j=1; j<C;++j){
			if(l[i][j]){
				l[i][j] += l[i][j-1];
			}else{
				l[i][j] = 0;
			}
		}
	}

	// r -> how many consequtive cells to right
	for(int i=0;i<R;++i){
		for(int j=C-2; j>=0; --j){
			if(r[i][j]){
				r[i][j] += r[i][j+1];
			}else{
				r[i][j] = 0;
			}
		}
	}

	for(int i=0;i<R;++i){
		for(int j=0;j<C;++j){
			// cout << endl <<  i  << " " << j << endl;
			if(in[i][j]){
				//  l ,u
				
				//// l is base -> l<u
				int temp1 = min({u[i][j]/2,l[i][j]});
				if(temp1>=2){
					ans += temp1-1;
				}

				//// u is base -> u<l
				int temp2 = min({u[i][j],l[i][j]/2});
				if(temp2>=2){
					ans += temp2-1;
				}

				// r ,u
				
				//// r is base -> r<u
				temp1 = min({u[i][j]/2,r[i][j]});
				if(temp1>=2){
					ans += temp1-1;
				}

				//// u is base -> u<r
				temp2 = min({u[i][j],r[i][j]/2});
				if(temp2>=2){
					ans += temp2-1;
				}

				// l ,d
				
				//// l is base -> l<d
				temp1 = min({d[i][j]/2,l[i][j]});
				if(temp1>=2){
					ans += temp1-1;
				}

				//// d is base -> d<l
				temp2 = min({d[i][j],l[i][j]/2});
				if(temp2>=2){
					ans += temp2-1;
				}

				// r, d
				
				//// r is base -> r<d
				temp1 = min({d[i][j]/2,r[i][j]});
				if(temp1>=2){
					ans += temp1-1;
				}

				//// d is base -> r<l
				temp2 = min({d[i][j],r[i][j]/2});
				if(temp2>=2){
					ans += temp2-1;
				}
			}
			// cout << ans << endl;
		}
	}


	cout << "Case #" << cs << ":" << " " << ans << endl;
}

int main(){
	int tt;
	cin >> tt;
	int ttt = tt;
	while(tt--){
		solve(ttt-tt);
	}

	return 0;
}
/*

1


*/