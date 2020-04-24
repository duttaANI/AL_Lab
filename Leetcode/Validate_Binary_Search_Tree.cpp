#include <iostream>
#include <bits/stdc++.h> 
#include <cstdlib>
#include <queue>
#include <string>
using namespace std;


//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

class Solution {
public:
   bool isValidBST(TreeNode* root, TreeNode* min=NULL, TreeNode* max=NULL) {
        if (!root) return true;
        if (min != NULL && root->val <= min->val) return false;
        if (max != NULL && root->val >= max->val) return false;
        return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
    }
};
/*
above approach is same as
class Solution {
public:
    bool isBST(TreeNode* root,int min, int max)
    {
        if(root==NULL )
            return true;
        
        if(root->val>=max || root->val<=min)
            return false;

        return isBST(root->left,min,root->val)  && isBST(root->right,root->val,max);
    }

    bool isValidBST(TreeNode* root) {
        return isBST(root,-2147483648,2147483647);
    }
};*/

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        bool ret = Solution().isValidBST(root);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
