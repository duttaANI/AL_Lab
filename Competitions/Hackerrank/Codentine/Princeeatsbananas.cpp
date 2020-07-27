#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int tot_Bananas(int bana, int n){
    int peels=bana;
    int ans = bana;
    bana = 0;
    while(peels>=n){
        bana = peels/n;
        ans += bana;
        peels = peels%n + bana;
        bana = 0;
    }
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T,p,c,n;
    cin >> T;
    for(int i=0; i<T; ++i){
        cin >> p >> c >> n;
        cout << tot_Bananas(p/c,n) << "\n";
    }
    return 0;
}
