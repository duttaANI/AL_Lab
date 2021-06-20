//Function to count number of nodes in BST that lie in the given range.
int getCount(Node *root, int l, int h)
{
    // your code goes here 
    // your code goes here
    if(root==NULL) return 0;
    int cnt = 0;
    bool flg = (root->data>=l && root->data<=h);
    if( (flg && root->data > l) || root->data > h ) cnt = getCount(root->left,l,h);
    if(flg || root->data < l) cnt += getCount(root->right,l,h);
    
    return flg + cnt;
}