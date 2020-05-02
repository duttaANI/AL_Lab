# include <stdio.h>
# include <stdlib.h>



int max(int a, int b)
{
    return a>b?a:b;
}


struct NODE 
{
    int data;
    int h;   //height
    struct NODE* left_child;
    struct NODE* right_child;
};

int height(struct NODE * n);

//---------------------AVL FUNCTIONS----------------------------
struct NODE* sh_lf(struct NODE* n)
{
    struct NODE* temp1,*temp2;
    temp1 = n->right_child;
    temp2 = temp1->left_child;
    
    //  rotate
    temp1->left_child=n;
    n->right_child=temp2;
    
    //  Update heights 
    n->h = max(height(n->left_child), height(n->right_child))+1; 
    temp1->h = max(height(temp1->left_child), height(temp1->right_child))+1; 
  

    return temp1;
}


struct NODE* sh_rt(struct NODE* n)
{
    struct NODE* temp1,*temp2;
    temp1 = n->left_child;
    temp2 = temp1->right_child;
    
    //rotate
    temp1->right_child=n;
    n->left_child=temp2;

    // Update heights 
    n->h = max(height(n->left_child), height(n->right_child))+1; 
    temp1->h = max(height(temp1->left_child), height(temp1->right_child))+1; 
  

    return temp1;
}

struct NODE* sh_RL(struct NODE* n)
{
    n->right_child = sh_rt(n->right_child);

    return sh_lf(n);
}

struct NODE* sh_LR(struct NODE* n)
{
    n->left_child = sh_lf(n->left_child);

    return sh_rt(n);
}


//---------------------END AVL FUNCTIONS----------------------





//=========================== SOME FUNCTIONS ===============================
int height(struct NODE * n)
{
    if(n)
        return max(height(n->left_child),height(n->right_child))+1;
    return 0;
}

int bal_factor(struct NODE * n)
{
    return height(n->left_child)-height(n->right_child);
}

void inorder(struct NODE* n)
{

    if(n)
    {
        inorder(n->left_child);
        printf("\tdat=%d,bf=%d",n->data,bal_factor(n));
        inorder(n->right_child);
    }
    
}

void preorder(struct NODE* n)
{

    if(n)
    {
        printf("\tdat=%d,bf=%d",n->data,bal_factor(n));
        preorder(n->left_child);
        preorder(n->right_child);
    }
    
}

struct NODE* newNode(int item) 
{ 
    struct NODE *temp =  (struct NODE *)malloc(sizeof(struct NODE)); 
    temp->data = item; 
    temp->left_child = temp->right_child = NULL; 
    return temp; 
} 


//===========================END SOME FUNCTIONS ===============================
struct NODE* root;  // GLOBAL ROOT !!!!!!!!!!!!!!!!!!!!!


struct NODE* insert1(struct NODE* n ,int key) 
{
    // insert like BST
    if (n == NULL) return newNode(key); 

   
    if     (key > n->data) {

        n->right_child  = insert1(n->right_child, key);
        if(bal_factor(n)==-2)
            if(key>n->right_child->data)
                n = sh_lf(n);
            else
                n = sh_RL(n);
        
    }
    else if(key < n->data) {

        n->left_child = insert1(n->left_child, key);   
        if(bal_factor(n)==2)
            if(key<n->left_child->data)
                n = sh_rt(n);
            else
                n = sh_LR(n);
    }
    else  // duplicates are not allowed
        return n;

    // update height
    n->h = 1 + max(height(n->left_child), height(n->right_child)); 

  
    return n; 

}



int main()
{
    root =NULL;
    printf("Create_Bin_Search_Tree\n");

    int insert =1,value;

    while(insert!=0)
    {
        printf( "enter value and insert( make insert=0 to print result )\n");
        scanf("%d%d",&value,&insert);
        if(insert!=0)
        root=insert1(root,value);
    }
    
    //printf("bf=%d",bal_factor(root));
    
    //fix_tree(root,NULL,0);

    printf("inorder =\n");
    inorder(root);
    printf("\n");

    printf("preorder =\n");
    preorder(root);
    printf("\n");

    return 0;
}

/*
sample i/o:
Create_Bin_Search_Tree
enter value and insert( make insert=0 to print result )
7 1
enter value and insert( make insert=0 to print result )
12 1
enter value and insert( make insert=0 to print result )
4 1
enter value and insert( make insert=0 to print result )
9 1
enter value and insert( make insert=0 to print result )
0 0 
inorder =
	dat=4,bf=0	dat=7,bf=-1	dat=9,bf=0	dat=12,bf=1
preorder =
	dat=7,bf=-1	dat=4,bf=0	dat=12,bf=1	dat=9,bf=0

*/
