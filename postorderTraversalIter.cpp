/*-----------iterative way-----------*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> r;
        stack<TreeNode*> s;
        TreeNode* _current_node = root;
        TreeNode* _last_node = NULL;
        
        while(_current_node || !s.empty())
        {
            if(_current_node)
            {
                s.push(_current_node);
                _current_node = _current_node->left;
            }
            else
            {
                TreeNode* _top_node = s.top();
                if(_top_node->right && _top_node->right != _last_node)
                {
                    _current_node = _top_node->right;
                }
                else
                {
                    r.push_back(_top_node->val);
                    _last_node = _top_node;
                    s.pop();
                }
            }
        }
    return r;
    }
};
