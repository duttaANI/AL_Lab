// using unordered_map
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;
    int idx = 1;
    unordered_map<int,int> tree;  tree[0]=1; tree[1]=3; tree[2]=8;
   //        2147483647
    while(tree[idx]!=N){
        tree[2*idx+1] = tree[idx]*10 +3;
        tree[2*idx+2] = tree[idx]*10 +8;
        ++idx;
    }
    
    cout << idx;
    return 0;
}

// using vector
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;
    int idx = 1;
    vector<int> tree(90000000,0);  tree[0]=1; tree[1]=3; tree[2]=8;
   //                2147483647
    while(tree[idx]!=N){
        tree[2*idx+1] = tree[idx]*10 +3;
        tree[2*idx+2] = tree[idx]*10 +8;
        ++idx;
    }
    
    cout << idx;
    return 0;
}


