
int countPathSum(TreeNode* root, long key) {
        if(!root) {
            return 0;
        }
        if(root->val == key) {
            return 1 + countPathSum(root->left, key-root->val) + 
            countPathSum(root->right, key-root->val);
        }
        return countPathSum(root->left, key-root->val) + 
            countPathSum(root->right, key-root->val);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) {
            return 0;
        }
        
        return countPathSum(root, targetSum) + pathSum(root->left, targetSum)
            + pathSum(root->right, targetSum);
    }
