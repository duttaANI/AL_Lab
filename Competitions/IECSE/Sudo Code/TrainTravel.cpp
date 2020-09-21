#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,x;


int waitTillTrainArrives(int b,int e,int t){


	if( b==e ){ // edge case
		return 0;
	}

	int wait,arrivalTime;

	int dir = ( t/(x-1) )%2; // 0-> +ve dir (right) , 1-> -ve dir (left)

	if( dir==1 && e<b ){
		arrivalTime = t + (b-e);
	}else 
	if( dir==0 && e>b ){
		arrivalTime = t + (e-b);
	}else
	if( dir==0 && e<b ){
		arrivalTime = t + 2*(x-b) + (b-e);
	}else
	if( dir==1 && e>b ){
		arrivalTime = t + 2*(b-1) + (e-b);
	}

	wait = arrivalTime - t;
	
	return wait;
}

int main(){
	int tt;
	cin >> n >> x;
	tt = n;
	while (tt--) {
		int b,e,t,arrivalTime;
		cin >> b >> e >> t;

		

		

		// get sation no. for train at time t
		int k=0;
		while( ( t - (x-1)*2*k + 1 ) > x  ){
			++k;
		}

		// cout << "k " << k << " waitTillTrain " << waitTillTrainArrives( t - (x-1)*2*k + 1 ,b ,t ) <<  " train station at time t " << ( t - (x-1)*2*k + 1 ) << "\n";

		int dir = ( ( t + waitTillTrainArrives( t - (x-1)*2*k + 1 ,b ,t ) )/(x-1) )%2; // 0-> +ve dir (right) , 1-> -ve dir (left)

		// cout << "dir " << dir << "\n";

		// if( b==e && ( t - (x-1)*2*k + 1 )==b ){ // edge case
		// 	cout << t << "\n";
		// 	continue;
		// }

		if( b==e ){
			cout << t << "\n";
			continue;
		}

		if( dir==1 && e<=b ){

			arrivalTime = t + (b-e) + waitTillTrainArrives( t - (x-1)*2*k + 1 ,b ,t );
		}else 
		if( dir==0 && e>=b ){
			arrivalTime = t + (e-b) + waitTillTrainArrives( t - (x-1)*2*k + 1 ,b ,t );
		}else
		if( dir==0 && e<=b ){
			arrivalTime = t + 2*(x-b) + (b-e) + waitTillTrainArrives( t - (x-1)*2*k + 1 ,b ,t );
		}else
		if( dir==1 && e>=b ){
			arrivalTime = t + 2*(b-1) + (e-b) + waitTillTrainArrives( t - (x-1)*2*k + 1 ,b ,t );
		}
		cout << arrivalTime << "\n";
	}

	return 0;
}