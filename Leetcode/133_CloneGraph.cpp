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
    
   Node* dfs(Node* node, unordered_map <Node *, Node *>& m){
        Node * newn = new Node(node->val);
        m[node] = newn;
        for( Node * nbr : node->neighbors ){
            if( m.find(nbr) != m.end() ){
                newn->neighbors.push_back(m[nbr]);
            }
            else{
                newn->neighbors.push_back( dfs(nbr,m) );
            }
        }
        return newn;
    }
   
    Node* cloneGraph(Node* node) {
        if(!node) { 
            return NULL;
        }         
        
        unordered_map <Node *, Node *> visited;
        
        return dfs(node,visited);
    }
};
