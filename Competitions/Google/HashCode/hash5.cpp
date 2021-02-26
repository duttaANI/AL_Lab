#include <bits/stdc++.h>
#define ar array
using namespace std;
 
int main()
{
    long long int P, D, I, S, V, F, B, E, T;
    cin >> D >> I >> S >> V >> F;
    vector<vector<pair<long long int, long long int>>> graph(I);
    unordered_map<long long int, long long int> cars_AT_V; //vertex,count
    unordered_map<string, ar<long long int, 3>> streets;
    //input
 
    while (S--)
    {
        string street_name;
        cin >> B >> E;
        cin >> street_name >> T;
        streets[street_name] = {T, B, E};
        graph[B].push_back({E, T});
    }
    vector<vector<string>> path;
    unordered_map<long long int, vector<long long int>> cars_n; //cars at each vertex
    int maxm = 0;
    for (long long int j = 0; j < V; j++)
    {
        cin >> P;
        string s;
        int i = 0;
        vector<string> vv;
        vector<long long int> vec(P, 0);
        while (P--)
        {
            cin >> s;
            vv.push_back(s);
            vec[i++] = streets[s][2];
            cars_n[streets[s][2]].push_back(j);
        }
        cars_AT_V[vec[0]]++; //count
        path.push_back(vv);
        if (cars_AT_V[vec[0]] > maxm)
            maxm = vec[0];
    }
    // code here
    // pq   count of cars at a vertex , vertex
    vector<vector<string>> ans(I);                         //address
    vector<vector<long long int>> green(I);                //time
    priority_queue<pair<long long int, long long int>> pq; //count,intersectn
    pq.push({cars_AT_V[maxm], maxm});
    vector<long long int> count(V, 0);
    vector<bool> vis(I, false);
    vis[maxm] = true;
    while (!pq.empty())
    {
        auto q = pq.top();
        pq.pop();
        for (auto x : cars_n[q.second])
        {
            //all cars at i
            ans[q.second].push_back(path[x][count[x]]);               //string
            green[q.second].push_back(streets[path[x][count[x]]][0]); //time
            count[x]++;
            int end = streets[path[x][count[x]]][2];
            cars_AT_V[end]++;
            cars_n[end].push_back(x);
        }
        for (auto g : graph)
        {
            for (auto t : g)
                if (!vis[t.first])
                {
                    // pq.push({cars_AT_V[t.first], t.first});
                    vis[t.first] = true;
                }
        }
    }
    //ans print
    long long int y = 0;
    for (auto r : ans)
    {
        if (r.size() != 0)
            y++;
    }
    cout << y << endl;
    for (long long int i = 0; i < I; i++)
    {
        if (ans[i].size() != 0)
        {
            cout << i << endl;
            for (long long int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " " << green[i][j] << endl;
            }
        }
    }
}
 
