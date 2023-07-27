int height(Node* root) {
        if(!root){
            return 0;
        }
        return 1+max(height(root->left), height(root->right));
    }
    
    int findMaxSum(Node* root, int height, int sum, int &maxi) {
        if(!root) {
            return 0;
        }
        int l = findMaxSum(root->left, height-1, sum+root->data, maxi);
        int r = findMaxSum(root->right, height-1, sum+root->data, maxi);
        if(!root->left && !root->right){
            if(height == 0){
                maxi = max(maxi, sum+root->data);
            } 
        }
        return root->data;
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        if(!root) {
            return 0;
        }
        int mx = INT_MIN;
        int ht = height(root);
        int sum = findMaxSum(root, ht-1, 0, mx);
        return mx;
    }
