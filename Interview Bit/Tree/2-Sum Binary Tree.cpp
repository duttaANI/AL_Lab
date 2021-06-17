/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void x_order(TreeNode* A,unordered_map<int,int>& mp){
    if(A!=NULL){
        mp[A->val]++;
        if(A->left)
        x_order(A->left,mp);
        if(A->right)
        x_order(A->right,mp);
    }
}
 
int Solution::t2Sum(TreeNode* A, int B) {
    unordered_map<int,int> mp;
    x_order(A,mp);
    for( auto i : mp  ){
        if( mp.find(B- (i.first) ) != mp.end() && B- (i.first)!= i.first ){
            return 1;
        }
    }
    return 0;
}
