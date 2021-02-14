// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
    public:
    vector<int> adj[26];
    string findOrder(string dict[], int N, int K) {
        //code here
        
        vector<int> vis(26,-1);
        int incoming[26] = {0};
        // cout << dict[0] << " " << dict[1] << endl;
        buildGraph(dict,vis,incoming,N);

        // cout << " graph is -> \n";
        // for(int i=0; i<26; ++i){
        //     cout << "i :" << i << " ";
        //     for(int v : adj[i]){
        //         cout << v << " ";
        //     }
        //     cout << endl;
        // }
        
        // cout << " vis is -> \n";
        // for(int i=0; i<26; ++i){
        //     if(vis[i]==0){
        //         cout << i << " i " << incoming[i] << endl;
        //     }
        // }
        
        string str="";

        queue<int> q;

        for(int i=0; i<26; ++i){
            if(incoming[i]==0 && vis[i]==0){
                // cout << " q " << i << endl;
                q.push(i);
            }
        }

        while(!q.empty()){
            int frnt = q.front(); q.pop();
            str += (char)(frnt+'a');
            for(int v : adj[frnt]){
                if(--incoming[v]==0){
                    q.push(v);
                }
            }
        }
        reverse(str.begin(), str.end());

        // cout << str << " ans \n";

        return str;
    }
    
    void buildGraph(string dict[],vector<int>& vis, int incoming[], int N ){

        for(int i=0; i<N; ++i){
            for( char c : dict[i] ){
                vis[c-'a'] = 0;
            }
            if( i>0 ){
                string w1 = dict[i-1];
                string w2 = dict[i];
                // cout << w1 << " w1 \n";
                // cout << w2 << " w2 \n";
                int len = min({ w1.size(), w2.size() });
                for(int j=0; j<len ;++j){
                    if(w1[j]!=w2[j]){
                        // cout << w1[j]-'a' << " " << w2[j]-'a' << endl;
                        adj[w2[j]-'a'].push_back(w1[j]-'a');
                        incoming[ w1[j]-'a' ]++;
                        break;
                    }
                }
            }
        
        }


        
        return ;
    }
};


// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //  cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends