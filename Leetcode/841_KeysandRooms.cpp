// DFS
class Solution {
public:
    
    void dfs(int S,vector<vector<int>> & graph, vector<bool>& vis) {
        vis[S] =true;
        for(int i=0 ;i<graph[S].size(); ++i) {
          if(!vis[graph[S][i]])
                dfs(graph[S][i], graph, vis);
        }
        return ;
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        vector<bool> vis (rooms.size(),false);
        dfs(0, rooms, vis);
        
        for (int i =0; i<vis.size(); ++i) {
            if (vis[i]==false) 
                return false;
        }
        return true;
    }
};




// My Slow BFS
class Solution {
public:
    
    void push_Q(queue<int>& Q,vector<int> Vec) {
        for(auto & V : Vec) {
            Q.push(V);
        }
        return ;
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> Q;
        vector<bool> visited (rooms.size(),false);
        visited[0] = true;
        
        if(rooms[0].size()>0)
        {
            push_Q(Q,rooms[0]);
        }
        
        while(!Q.empty()) {
            int room = Q.front();
            if(!visited[room]) {
                visited[room] =true;
                if (rooms[room].size()>0) {
                    push_Q(Q,rooms[room]);
                }
            }
            Q.pop();
        }
        
        for (int i =0; i<visited.size(); ++i) {
            if (visited[i]==false)
                return false;
        }
        return true;
    }
};

// BFS refactored
class Solution {
public:
    
    void push_Q(queue<int>& Q,vector<int> Vec) {
        for(auto & V : Vec)
            Q.push(V);
        return ;
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> Q;
        vector<bool> visited (rooms.size(),false);
        visited[0] = true;
        push_Q(Q,rooms[0]);
        
        while(!Q.empty()) {
            int room = Q.front();
            if(!visited[room]) {
                visited[room] =true;
                push_Q(Q,rooms[room]);
            }
            Q.pop();
        }
        
        for (int i =0; i<visited.size(); ++i) {
            if (visited[i]==false)
                return false;
        }
        return true;
    }
};