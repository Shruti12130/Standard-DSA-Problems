int findRootIndex(vector<int> &in, int key) {
        for(int i=0;i<in.size();i++) {
            if(in[i] == key) {
                return i;
            }
        }
        return -1;
    }
    
    TreeNode* buildTree(vector<int> &pre, vector<int> &in, int &ind, int start, int end) {
        if(start > end) {
            return NULL;
        }
        int idx = findRootIndex(in, pre[ind]);

        TreeNode* root = new TreeNode(pre[ind++]);
        root->left = buildTree(pre, in, ind, start, idx-1);
        root->right = buildTree(pre, in, ind, idx+1, end);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ind = 0;
        return buildTree(preorder, inorder, ind, 0, inorder.size()-1);
    }
