vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<vector<int>> tree;
        queue<TreeNode*> node;
        node.push(root);
        while(!node.empty()) {
            int size = node.size();
            vector<int> vec;
            for(int i=0;i<size;i++){
                TreeNode* temp = node.front();
                vec.push_back(temp->val);
                node.pop();
                if(temp->left) {
                    node.push(temp->left);
                }
                if(temp->right) {
                    node.push(temp->right);
                }
            }
            tree.push_back(vec);
        }
        return tree;
}
