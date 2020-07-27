#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

void revstr(string s){
    stringstream stream(s);
    vector<string> words;
    
    for ( string word; stream >> word; )
    {
        words.push_back(word);
    }
    reverse(words.begin(), words.end());
    for(unsigned i=0; i<words.size(); ++i){
        cout << words[i] << " ";
    }
    cout << "\n";
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T,i;
    string s;
    cin >> T;
    // read the newline character
    getchar();
    for(i=0; i<T;++i){
        getline(cin, s);
        revstr(s);
    }
    return 0;
}
