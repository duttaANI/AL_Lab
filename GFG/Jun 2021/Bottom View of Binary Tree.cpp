void printBottom(Node* node, int dist, int level, auto &map)
{
    // base case: empty tree
    if (node == nullptr) {
        return;
    }
 
    // if the current level is more than or equal to the maximum level seen so far
    // for the same horizontal distance or horizontal distance is seen for
    // the first time, update the map
 
    if (level >= map[dist].second)
    {
        // update value and level for the current distance
        map[dist] = { node->data, level };
    }
 
    // recur for the left subtree by decreasing horizontal distance and
    // increasing level by 1
    printBottom(node->left, dist - 1, level + 1, map);
 
    // recur for the right subtree by increasing both level and
    // horizontal distance by 1
    printBottom(node->right, dist + 1, level + 1, map);
}
 
// Function to print the bottom view of a given binary tree
void printBottom(Node* root, vector<int> & ans)
{
    // create an empty map where
    // `key` —> relative horizontal distance of the node from the root node, and
    // `value` —> pair containing the node's value and its level
 
    map<int, pair<int, int>> map;
 
    // perform preorder traversal on the tree and fill the map
    printBottom(root, 0, 0, map);
 
    // traverse the map and print the bottom view
    for (auto it: map) {
        // cout << it.second.first << " ";
        ans.push_back(it.second.first);
    }
}

//Function to return a list containing the bottom view of the given tree.
vector <int> bottomView(Node *root)
{
   // Your Code Here
   vector<int> ans;
   printBottom(root,ans);
   return ans;
}