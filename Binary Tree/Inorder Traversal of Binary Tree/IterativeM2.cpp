vector<int> inorderTraversal(TreeNode* root) {
        vector<int> tree;
        TreeNode* curr = root;
        while(curr) {
            if(!curr->left) {
                tree.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* temp = curr->left;
                while(temp->right) {
                    temp = temp -> right;
                }
                temp->right = curr;
                TreeNode* node = curr;
                curr = curr->left;
                node->left = NULL;
            }
        }
        return tree;
    }
