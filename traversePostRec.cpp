/*
Binary Tree Postorder Traversal

Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
-------------Recursive way-------------
*/
class Solution {
public:
    void traversePost(TreeNode* root, std::vector<int> &v)
    {
        if (root != NULL)
        {
            /*root - right - left*/
            traversePost(root->left, v);
            traversePost(root->right, v);
            v.push_back(root->val);
        }
    }
    
    std::vector<int> postorderTraversal(TreeNode* root) 
    {        
        std::vector<int> v{};
        traversePost(root, v);
        return v;
    }
};
