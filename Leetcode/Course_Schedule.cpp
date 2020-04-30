#include <iostream>
#include <bits/stdc++.h> 
#include <cstdlib>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> Graph[numCourses]; // array of vectors
        vector<int> incoming(numCourses,0);
        
        int i,c;
        queue<int> q;
        
        // create a adj list graph
        for(auto& p :prerequisites)
        {
            Graph[p[1]].push_back(p[0]);
            incoming[p[0]]++;
        }
        
        //Kahn's algo
        for(i=0;i<incoming.size();++i) if(incoming[i]==0) q.push(i);
        
        while(!q.empty())
        {
            int c = q.front(); q.pop();
            for(auto&u:Graph[c]){
                if(--incoming[u]==0) q.push(u);
            }
        }
        
        //if any node left in graph(indegree of some node!=0) return false else return true
        for(i=0;i<incoming.size();++i) if(incoming[i]!=0)return false;
        return true;
    }
};