/*
    Time Complexity: O(N*2)
    Space Complexity: O(N)

    Where N is the number of elements in the array.
*/

//    Defining the BST node structure
template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

//    Function that inserts node in a BST and returns its root
TreeNode<int> *insertBST(TreeNode<int> *root, int value, TreeNode<int> *&successor)
{
    //    Checking if the root is NULL
    if (root == NULL)
    {
        root = new TreeNode<int>(value);
        return root;
    }

    //    Comparing the root's data with the value to be inserted to decide which subtree to call
    if (root->data > value)
    {
        successor->data = root->data;
        root->left = insertBST(root->left, value, successor);
    }
    else
    {
        root->right = insertBST(root->right, value, successor);
    }

    //    Returning the root of the BST
    return root;
}

vector<int> leastGreaterElement(vector<int> &arr)
{

    //    Finding the number of elements
    int n = arr.size();

    //    Defining the root of the tree
    TreeNode<int> *root = NULL;

    //    Iterating through the array
    for (int i = n - 1; i >= 0; i--)
    {
        //    Defining the successor node
        TreeNode<int> *successor = new TreeNode<int>(-1);

        //    Inserting node into the BST
        root = insertBST(root, arr[i], successor);

        //    Assinging inorder successor
        arr[i] = successor->data;
    }

    delete root;

    return arr;
}