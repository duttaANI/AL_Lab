void traverse(Node * node, bool &b, int l,int r){
    if(!b || !node) return ;
    
    if(l==r || r==1)
    b=0;
    
    traverse(node->left,b,l,node->data-1);
    traverse(node->right,b,node->data+1,r);
}

bool isDeadEnd(Node *root)
{
    //Your code here
    bool b =1;
    traverse(root,b,INT_MIN,INT_MAX);
    return !b;
}