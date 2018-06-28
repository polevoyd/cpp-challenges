/*
Definition for a binary tree node.
struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;  
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
 /* 	preorder traversal 	*/ 
 /* 	root - left - right	*/
 /* 
 since we doing recursion, we can't create vector inside of recursion
and have to split function to two functions: one accepting a root and vector
and doing traversal and another one takes root, creates empty vector and
applying first function to it 
*/
class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) 
    {
		std::vector<int> rt{};
        calculateAndReturn(root, rt);
        return rt;
    }
    
    void calculateAndReturn(TreeNode *root, std::vector<int> &v)
    {
        if ( root != NULL )                     // if node is not empty, cause otherwise nothing to add
        { 
            v.push_back(root->val);             // adding value to a vector
            calculateAndReturn( root->left, v);  // going to left child and repeat previous steps 
            calculateAndReturn( root->right, v); // going to right child and repeat previous steps 
        }
    }
};
/* 
BUT we can also do that just using a static variable 
and add values directly to it 
*/
static std::vector<int> v{};
class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) 
    {
        if ( root != NULL )                  // if node is not empty, cause otherwise nothing to add
        { 
            v.push_back(root->val);          // adding current |root| value to a vector
            preorderTraversal( root->left);  // going to |left| child and repeat previous steps 
            preorderTraversal( root->right); // going to |right| child and repeat previous steps 
        }
        return v;
    }
};
