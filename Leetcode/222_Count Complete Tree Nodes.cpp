/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes2(TreeNode* root) {
        if(!root){
            return -1;
        }
        return countNodes2(root->left) + countNodes2(root->right) + 2;
    }
    
    int countNodes(TreeNode* root) {
        
        return countNodes2(root) + 1;
    }
};



// FASTER 20ms

class Solution {
public:
    int find(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int lc=0,rc=0;
        TreeNode* temp=root;
        while(temp)
        {
            temp=temp->left;
            lc++;
        }
        temp=root;
        while(temp)
        {
            temp=temp->right;
            rc++;
        }
        if(lc==rc)
            return pow(2,lc)-1;
        return 1+find(root->left)+find(root->right);
    }
    int countNodes(TreeNode* root) {
        return find(root);      
    }
};