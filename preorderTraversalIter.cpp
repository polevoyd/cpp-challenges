class Solution {
public:
    std::vector<int> v{};
    std::vector<int> preorderTraversal(TreeNode* root) 
    {
        std::vector<int> v{};
        std::stack<TreeNode*> s{};
        if (root == NULL)   // if input empty
            return v;       // then return vector
        else
        {
            s.push(root);       // adding this root to stack
            while(!s.empty())   // while stack is not empty
            {
                TreeNode *tmp = s.top();     //temp node that will be a link to top one
                v.push_back(tmp->val);       // push the root's value into a vector
                s.pop();                     //pop the temp node from stack
                                            // since stack is FILO
                if(tmp->right != NULL)      // if right node not empty
                    s.push(tmp->right); // then push it to stack
                if(tmp->left != NULL)       // if left node not empty
                    s.push(tmp->left);  // then push it to stack too
            }
        return v;
        }
    }
};
