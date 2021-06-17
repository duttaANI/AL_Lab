/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void x_order(TreeNode* A, int B, priority_queue<int>& pq){
    if(A==NULL){
        return ;
    }
    pq.push(A->val);
    if(pq.size()>B){
        pq.pop();
    }
    x_order(A->right,B,pq);
    x_order(A->left,B,pq);
}
 
int Solution::kthsmallest(TreeNode* A, int B) {
    priority_queue<int> pq;
    x_order(A,B,pq);
    return pq.top();
}
