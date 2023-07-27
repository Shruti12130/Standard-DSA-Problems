vector<int> inorderTraversal(TreeNode* root) {
        vector<int> tree;
        stack<TreeNode*> st;
        TreeNode* currentNode = root;
        
        while(currentNode || !st.empty()) {
            while(currentNode) {
                st.push(currentNode);
                currentNode = currentNode->left;
            }
            
            currentNode = st.top();
            st.pop();
            tree.push_back(currentNode->val);
            currentNode = currentNode->right;
        }
        return tree;
}
