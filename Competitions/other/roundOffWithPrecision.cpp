#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;




void soluton_function(){
	
	float n;
	cin >> n;
	int i;
	cin >> i;

	string s = "%0.";

	s += to_string(i);

	s += "f";

	char * input = (char*)malloc(sizeof(s)*sizeof(char));

	for(int i=0; i<sizeof(s);++i){
		input[i] = s[i];
	}


	printf(input, n);

    }
	int main(){

		soluton_function();
		return 0;
}

