class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> Graph[numCourses]; // array of vectors
        vector<int> incoming(numCourses,0);
        vector<int> topologicalOrder;
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
            topologicalOrder.push_back(c);
            for(auto&u:Graph[c]){
                if(--incoming[u]==0) q.push(u);
            }
        }
        
        if(topologicalOrder.size()==numCourses) return topologicalOrder;
        return {};
    }
};