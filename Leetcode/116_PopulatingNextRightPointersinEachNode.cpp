/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    void levelOrder (Node* node, queue<Node*>& Q, int count_ele, int ele ) {
        
        if (node) {
            
            if( ele ==count_ele ) {
                Q.push(NULL);
                ele = 2*ele + 1;
            }
            
            Q.push(node->left);  ++count_ele; Q.push(node->right); ++count_ele;
            
            
            Node* n = Q.front();   Q.pop();
            n->next = Q.front();   
            if(!n->next)
                Q.pop();
            
            levelOrder(Q.front() , Q, count_ele, ele);
        }
    }
    
    Node* connect(Node* root) {
        
        queue<Node *> Q;
        Q.push(root);
        levelOrder (root, Q,1,1);
        return root;
    }
};