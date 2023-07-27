int height(TreeNode* root) {
        if(!root){
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int h = height(root);
        vector<vector<int>> tree(h);
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
            tree[h-1] = temp;
            h--;
        }
        
        return tree;
    }
