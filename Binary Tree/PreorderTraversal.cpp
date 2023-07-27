vector<int> tree;
    
    void inorder(TreeNode* root) {
        if(!root) {
            return;
        }
        tree.push_back(root->val);
        inorder(root->left);
        inorder(root->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return tree;
    }

//Method-2

vector<int> preorderTraversal(TreeNode* root){
        vector<int> tree;
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if(node){
                tree.push_back(node->val);
                st.push(node->left);
                st.push(node->right);
            }
        }
        return tree;
    }
