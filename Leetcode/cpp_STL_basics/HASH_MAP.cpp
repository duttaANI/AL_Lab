#include <iostream>
#include <bits/stdc++.h> 
#include <cstdlib>
#include <queue>
#include <string>
using namespace std;

int main() {
    unordered_map<char, int> freq_map;
    vector<char> V{'a', 'b', 'a', 'c'};
 
    for (auto chr: V) {

        freq_map[chr]++;
    }
 
    for (auto it: freq_map) {
        std::cout << it.first << " - " << it.second <<  '\n';
    }
 
    return 0;
}
