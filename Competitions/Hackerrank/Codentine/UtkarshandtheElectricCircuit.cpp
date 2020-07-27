#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
# define MAX 2147483647
using namespace std;

/*
0 0 0 0 0 
0 0 2 0 0 
0 2 0 3 8 
0 0 3 0 2 
0 0 8 2 0
*/

double min(double a,double b)
{
  if(a<b)
    return(a);
  else
    return(b);
}

double multiply(double x, double y){
  if(x==MAX || y==MAX)
  return MAX;
  else return x*y; 
}

void floyds(vector<vector<double> >& adj_mat,double n)
{
    int i,j,k;

    for(k=0;k<n;k++)  // for traversing all nodes
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            adj_mat[i][j]=min(adj_mat[i][j],  multiply(adj_mat[i][k],adj_mat[k][j]) );
          
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,ans,src,dst,edge,s,d;
    
    cin >> n;
    vector<vector<double> > graph (n, vector<double> (n, MAX) );
    cin >> edge;
    for(int x=0; x<edge;x++){
        cin >> s >> d >> graph[s][d];
        graph[d][s] = graph[s][d];
    }

    // for(int i=0; i<n; i++){
    //   for(int j=0; j<n; ++j){
    //     cout << graph[i][j] << " ";
    //   }
    //   cout << "\n";
    // }

    cin >> src >> dst;
    floyds (graph,n);
    // for(int i=0; i<n; i++){
    //   for(int j=0; j<n; ++j){
    //     cout << graph[i][j] << " ";
    //   }
    //   cout << "\n";
    // }
    ans=(graph[src][dst]!=MAX)?graph[src][dst]:-1;
    cout << ans ;
    
    return 0;
}
