
//Function to find the lowest common ancestor in a BST. 
Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   Node * a = root , * b = root;
   Node * lca = NULL;
   while( a && b && (a->data!=n1 || b->data!=n2 ) ){
       if(a==b){
           lca = a;
       }
       
       if(a->data<n1)
       a = a->right;
       else if (a->data>n1)
       a = a->left;
       
       if(b->data<n2)
       b = b->right;
       else if (b->data>n2)
       b = b->left;
       
   }
   if(a&&b)
   return lca;
   return NULL;
}