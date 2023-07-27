vector<int> tree;
    
    void inorder(TreeNode* root) {
        if(!root) {
            return;
        }
        inorder(root->left);
        tree.push_back(root->val);
        inorder(root->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return tree;
    }
