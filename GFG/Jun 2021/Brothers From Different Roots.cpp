void dfs(Node * node, unordered_map<int,int>& m){
    if(node){
        m[node->data]++;
        dfs( node->left , m );
        dfs( node->right, m );
    }
}


int countPairs(Node* root1, Node* root2, int x)
{
    // Code here
    unordered_map<int,int> m1,m2;
    dfs(root1,m1);
    dfs(root2,m2);
    int ans=0;
    
    for( auto it : m1 ){
        // cout << it.first << " " << it.second <<endl;
        if( m2[ (x- it.first) ] >0 ){
            ++ans;
        }
    }
    return ans;
}