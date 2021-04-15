/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
TreeNode * dfs( vector<int>& a, int l, int r ){
    if( l<=r ){
        int mid = l + (r-l)/2;
        TreeNode * T = new TreeNode(a[mid]);
        T-> left = dfs( a, l,mid-1 );
        T-> right = dfs(a,mid+1,r);
        return T;
    }
    return NULL;
}
 
 
TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    vector<int> a;
    ListNode * cur = A;
    while( cur ){
        a.push_back( cur->val );
        cur = cur->next;
    }
    
    int l = 0, r = a.size()-1;
    TreeNode * T = dfs ( a,l,r );
    return T;
}
