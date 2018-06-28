/* Binary Tree Inorder Traversal */
/*
Definition for a binary tree node.
struct TreeNode {
int val;
TreeNode *left;   
TreeNode *right;  
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
class Solution {
public:
    void calculateIntoVector(TreeNode* root, std::vector<int> &v)
    {
        if (root != NULL)
        {
            calculateIntoVector(root->left, v);
            v.push_back(root->val);
            calculateIntoVector(root->right, v);
        }
    }
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> r{};
        calculateIntoVector(root, r);
        return r;
    }
};
