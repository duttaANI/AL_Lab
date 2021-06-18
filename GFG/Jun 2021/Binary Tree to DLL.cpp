// This function should return head to the DLL
class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    
    void convert(Node* root, Node* &head)
    {
        // base case: tree is empty
        if (root == nullptr) {
            return;
        }
     
        // recursively convert the right subtree first
        convert(root->right, head);
     
        // insert the current node at the beginning of a doubly linked list
        root->right = head;
     
        if (head != nullptr) {
            head->left = root;
        }
     
        head = root;
     
        // recursively convert the left subtree
        convert(root->left, head);
    }
    
    
    Node * bToDLL(Node *root)
    {
        // your code here
        // head of the doubly linked list
        Node* head = NULL;
     
        // convert the above binary tree into doubly linked list
        convert(root, head);
        
        return head;
    }
};