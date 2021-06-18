class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    
    void printTop(Node* root, int dist, int level, auto &map)
    {
        // base case: empty tree
        if (!root) {
            return;
        }
     
        // if the current level is less than the maximum level seen so far
        // for the same horizontal distance, or if the horizontal distance
        // is seen for the first time, update the map
        if (map.find(dist) == map.end() || level < map[dist].second)
        {
            // update value and level for current distance
            map[dist] = { root->data, level };
        }
     
        // recur for the left subtree by decreasing horizontal distance and
        // increasing level by 1
        printTop(root->left, dist - 1, level + 1, map);
     
        // recur for the right subtree by increasing both level and
        // horizontal distance by 1
        printTop(root->right, dist + 1, level + 1, map);
    }
     
    // Function to print the top view of a given binary tree
    void printTop(Node* root,vector<int> & ans)
    {
        
        // create an empty map where
        // `key` —> relative horizontal distance of the node from the root node, and
        // `value` —> pair containing the node's value and its level
        map<int, pair<int, int>> map;
     
        // perform preorder traversal on the tree and fill the map
        printTop(root, 0, 0, map);
     
        // traverse the map and print the top view
        for (auto it: map) {
            // cout << it.second.first << " ";
            ans.push_back(it.second.first);
        }
    }
    
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        printTop(root,ans);
        return ans;
    }

};



// doesnt work left view + right view
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    
   
    
    unordered_map< Node *, int > vis;
    
    void right_view(Node* node, vector<int>& ans, int level) {
        if(node && !vis[node]) {
            vis[node] = 1;
            if(level>=ans.size())
            
            ans.push_back(node->data);
            ++level;
            right_view(node->right, ans, level);
            right_view(node->left , ans, level);
            --level;
        }
    }
    
    vector<int> rightSideView(Node* root) {
        vector<int> ans;
        right_view(root, ans, 0);
        return ans;
    }
    
    void left_view(Node* node, vector<int>& ans, int level) {
        if(node && !vis[node]) {
            vis[node] = 1;
            if(level>=ans.size())
            
            ans.push_back(node->data);
            ++level;
            left_view(node->left, ans, level);
            left_view(node->right , ans, level);
            --level;
        }
    }
    
    vector<int> leftSideView(Node* root) {
        vector<int> ans;
        left_view(root, ans, 0);
        return ans;
    }
    
    vector<int> topView(Node *root)
    {
        
        Your code here
        vector<int> l,r;
        
        l=leftSideView(root);
        r=rightSideView(root);
        // reverse l
        reverse(l.begin(),l.end());
        
        vector<int> ans;
        
        for(int i=0;i<l.size()-1;++i){
            ans.push_back(l[i]);
        }
        ans.push_back(root->data);
        for(int i=1;i<r.size();++i){
            ans.push_back(r[i]);
        }
        
        return ans;
    }

};