class Solution
{
public:

    void order(Node* root,vector<Node*>&v )
    {
        if(root==NULL)return;
        order(root->left,v);
        v.push_back(root);
        order(root->right,v);
    }
    
    void populateNext(Node *root)
    {
        //code here
        
        vector<Node*> v;
        order(root,v);
        for(int i=0;i<v.size()-1;i++)
        {
            Node* temp=v[i];
            temp->next=v[i+1];
        }
    }
};