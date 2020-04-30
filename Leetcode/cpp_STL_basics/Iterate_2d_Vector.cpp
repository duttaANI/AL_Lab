#include <iostream>
#include <bits/stdc++.h> 
#include <cstdlib>
#include <queue>
#include <string>
using namespace std;

int main() 
{ 
    // Initializing 2D vector "vect" with 
    // values 
    vector<vector<int> > vect{ { 1, 2, 3 }, 
                               { 4, 5, 6 }, 
                               { 7, 8, 9 } }; 

    for(auto& p:vect){
    	cout << p[0] << " " << p[1] << " " << p[2] << "\n";
           
    }
  
    /*// Displaying the 2D vector 
    for (int i = 0; i < vect.size(); i++) { 
        for (int j = 0; j < vect[i].size(); j++) 
            cout << vect[i][j] << " "; 
        cout << endl; 
    } */
  
    return 0; 
} 