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

#define ar array

class Solution {
public:
    unordered_map<int,int> mp;

    int dfs(TreeNode* n){
        if(n){
            int l=0,r=0;
            l+=dfs(n->left);
            r+=dfs(n->right);
        
            mp[(n->val+l+r)]++;
            return (n->val+l+r);
        }
        else{
            return 0;
        }   
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        vector< ar<int,2>> freq;
        
        if( root ){
            dfs(root);
        }
        
        for( auto i : mp  ){
            freq.push_back({ i.second, i.first });
        }
        
        sort( freq.begin(), freq.end() );
        reverse( freq.begin(), freq.end() );
        
        
        int k=0;
        int f = freq[k][0];
        while(  k<freq.size() && freq[k][0] == f ){
            ans.push_back( freq[k][1] );
            ++k;
        }
        
        return ans;
    }
};
