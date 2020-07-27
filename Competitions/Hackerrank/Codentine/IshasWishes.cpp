#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int reverse, copy, x, digit;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin >> x;
    copy = x;
    reverse = 0;
    while(copy>0){
        digit = copy%10;
        reverse = reverse*10 + digit;
        copy = copy/10;
    }
    
    if(reverse == x){
        cout << 1;
        return 1;
    }
    return 0;
}
