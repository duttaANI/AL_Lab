/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node *node, Node *tempcopy, unordered_map<Node *, Node *> &visited) { 
        for(Node *i : node->neighbors) { 
            if(visited.find(i) == visited.end()) { 
                Node *copy = new Node(i->val, {});  
                visited[i] = copy; 
                dfs(i, copy, visited);
            } 
            tempcopy->neighbors.push_back(visited[i]);
        } 
    }
    
    Node* cloneGraph(Node* node) {
        if(!node) { 
            return NULL;
        }         
        
        unordered_map <Node *, Node *> visited; 
        
        Node *tempcopy = new Node(node->val, {}); 
        
        visited[node] = tempcopy; 
        
        dfs(node ,tempcopy, visited); 
        
        return tempcopy;
    }
};