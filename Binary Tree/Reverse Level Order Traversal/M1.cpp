vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> tree;
        if(!root) {
            return {};
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> temp;
            for(int i=0;i<size;i++){
                TreeNode* it = q.front();
                temp.push_back(it->val);
                q.pop();
                if(it->left) {
                    q.push(it->left);
                }
                if(it->right) {
                    q.push(it->right);
                }
            }
            tree.push_back(temp);
        }
        reverse(tree.begin(), tree.end());
        return tree;
    }
