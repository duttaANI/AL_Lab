# include <stdio.h>
# include <stdlib.h>

int max(int a, int b)
{
    return a>b?a:b;
}


struct NODE 
{
    int data;
    int bf;
    struct NODE* left_child;
    struct NODE* right_child;
};

//---------------------AVL FUNCTIONS----------------------------
struct NODE* sh_lf(struct NODE* n)
{
    struct NODE* temp1,*temp2;
    temp1 = n->right_child;
    temp2 = n->right_child->left_child;
    
    temp1->left_child=n;
    n->right_child=temp2;
    printf("success\n");
    return temp1;
}

struct NODE* sh_rt(struct NODE* n)
{
    struct NODE* temp1,*temp2;
    temp1 = n->left_child;
    temp2 = n->left_child->right_child;
    
    n->left_child->right_child=n;
    n->left_child=temp2;

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
        printf("\tdat=%d,bf=%d",n->data,n->bf);
        inorder(n->right_child);
    }
    
}

void reset_bal_factor(struct NODE* n)
{
    if(n)
    {
        n->bf = bal_factor(n);
        //printf("bf=%d,data=%d\n",n->bf,n->data );
        reset_bal_factor(n->left_child);
        reset_bal_factor(n->right_child);
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
    //printf("\ninserting\n");
    if (n == NULL) return newNode(key); 

   
    if (key > n->data) {

        n->right_child  = insert1(n->right_child, key);
        reset_bal_factor(root);
        if(n->bf==-2)
            if(key>n->right_child->data)
                n = sh_lf(n);
            else
                n = sh_RL(n);
    }
    else {
        n->left_child = insert1(n->left_child, key);   
        reset_bal_factor(root);
        if(n->bf==2)
            if(key<n->left_child->data)
                n = sh_rt(n);
            else
                n = sh_LR(n);
    }
  
    return n; 

}



int main()
{
    root =NULL;
    printf("Create_Bin_Search_Tree\n");

    int insert =1,value;

    while(insert!=0)
    {
        printf( "enter value: , insert\n");
        scanf("%d%d",&value,&insert);
        if(insert!=0)
        root=insert1(root,value);
    }
    
    //printf("bf=%d",bal_factor(root));
    reset_bal_factor(root);
    //fix_tree(root,NULL,0);

    printf("inorder =\n");
    inorder(root);

    return 0;
}































