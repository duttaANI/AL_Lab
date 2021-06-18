Node* util(int inOrder[],int levelOrder[],int start,int end,int i,int n){
    //End Case
    if(i>=n)
        return NULL;
    //Code
    struct Node* root=(struct Node*)malloc(sizeof(struct Node));
    root->key=levelOrder[i];
    root->left=root->right=NULL;
    int j=start;
    while(inOrder[j]!=levelOrder[i]&&j<=end)j++;//finding node in inorder to split array in left and right tree
    //recursive Case
    root->left=util(inOrder,levelOrder,start,j,2*i+1,n);//left tree
    root->right=util(inOrder,levelOrder,j+1,end,2*i+2,n);//right tree
    return root;
}


Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{
    //add code here.
    return util(inorder,levelOrder,iStart,iEnd,0,n);
}