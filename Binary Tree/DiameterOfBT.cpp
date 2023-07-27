int findDiameter(TreeNode* root, int &maxi) {
        if(!root) {
            return 0;
        }
        int left = findDiameter(root->left, maxi);
        int right = findDiameter(root->right, maxi);
        
        maxi = max(maxi, left + right);
        return 1 + max(left, right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        int k = findDiameter(root, diameter);
        return diameter;
    }
