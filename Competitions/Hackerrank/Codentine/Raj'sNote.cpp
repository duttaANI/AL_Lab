#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<string, vector<string>> mp;

vector<string> merge(string word, vector<string> prev){
    for(int i=0;i<prev.size();++i){
        prev[i]+=" "+word;
    }
    return prev;
}

vector<string> extractWord(string s, unordered_set<string>& dict) {
    if(mp.count(s)) return mp[s]; 
    vector<string> result;
    if(dict.count(s)){ 
        result.push_back(s);
    }
    for(int i=1;i<s.size();++i){
        string word=s.substr(i);
        if(dict.count(word)){
            string rem=s.substr(0,i);
            vector<string> prev=merge(word,extractWord(rem,dict));
            result.insert(result.end(),prev.begin(), prev.end());
        }
    }
    mp[s]=result; 
    return result;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    string s,d;
    int Dsize;
    cin >> s;
    cin >> Dsize;
    unordered_set<string> dict;
    for(int i=0; i<Dsize; ++i){
        cin >> d;
        dict.insert(d) ;
    }
    vector<string> ans = extractWord( s,dict);
    
    sort(ans.begin(),ans.end(), greater <>());
    
    if(ans.empty())
        cout << "[]";
    else
    for(int i=0; i<ans.size();++i){
        cout << ans[i] << "\n";
    }
    
    return 0;
}

