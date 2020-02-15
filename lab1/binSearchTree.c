// C program to demonstrate insert operation in binary search tree 
#include<stdio.h> 
#include<stdlib.h> 
#include <iostream>
using namespace std;
   
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
   
// A utility function to create a new BST node 
struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
// A utility function to do inorder traversal of BST 
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->key); 
        inorder(root->right); 
    } 
} 
   
/* A utility function to insert a new node with given key in BST */
struct node* insert1(struct node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left  = insert1(node->left, key); 
    else if (key > node->key) 
        node->right = insert1(node->right, key);    
  
    /* return the (unchanged) node pointer */
    return node; 
}

int findHeight(struct node* aNode) {
    if (aNode == NULL) {
        return -1;
    }

    int lefth = findHeight(aNode->left);
    int righth = findHeight(aNode->right);

    if (lefth > righth) {
        return lefth + 1;
    } else {
        return righth + 1;
    }
} 

/* Print nodes at a given level */
void printGivenLevel(node* root, int level)  
{  
    if (root == NULL)  
        return;  
    if (level == 1)  
        cout << root->key << " ";  
    else if (level > 1)  
    {  
        printGivenLevel(root->left, level-1);  
        printGivenLevel(root->right, level-1);  
    }  
}

/* Function to print level  
order traversal a tree*/
void printLevelOrder(node* root)  
{  
    int h =  findHeight(root);  
    int i;  
    for (i = 1; i <= h+1; i++)  
       { printGivenLevel(root, i);}
}  
 
// C function to search a given key in a given BST 
struct node* search(struct node* root, int key) 
{ 
    // Base Cases: root is null or key is present at root 
    if (root == NULL || root->key == key) 
       return root; 
     
    // Key is greater than root's key 
    if (root->key < key) 
       return search(root->right, key); 
  
    // Key is smaller than root's key 
    return search(root->left, key); 
} 


int main()
{
    // get root
    struct node* root = NULL;
	int insert =1,value,skey;

	while(insert!=0)
	{
		std::cout << "enter value: , insert\n";
        std::cin >> value;
        std::cin >> insert;
        if(insert!=0)
        root=insert1(root,value);
	}

    // print inoder traversal of the BST 
    inorder(root); 
    std::cout << "height of tree is:" << findHeight(root) << "\n";

    std::cout << "tree is: \n";
    printLevelOrder(root);

    std::cout << "enter key to search\n";
    std::cin >> skey;
    if(search( root, skey))
    	std::cout << "element present\n";
    else
    {
    	std::cout << "element not present , so inserting\n";
    	insert1(root,skey);
    }
   
    return 0; 
    

}
