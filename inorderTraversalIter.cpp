std::vector<int> inorderTraversal(TreeNode* root) {
        
        std::vector<int> r{};
        // if root is null then just return empty vector
        if (root == NULL) return r;
        //if not, we are creating an empty stack
        std::stack<TreeNode*> st{};
        TreeNode* current = root;
        // while current not empty or stack not empty
        while (current || !st.empty()) 
        {
            //specifically, while current not empty
            //we pushing it to stack and moving to left
            while (current) 
            {
                st.push(current);
                current = current->left;
            }
            //okay, now current is NULL
            // so we making current pack to
            //previous one (top of stack)
            current = st.top();
            //and pop it from stack
            st.pop();
            //adding current value to vector
            r.push_back(current->val);
            //and moving to right
            current = current->right;
        }
        return r;
    }
