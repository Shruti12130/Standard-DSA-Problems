int findSum(Node* root) {
        if(!root) {
            return 0;
        }
        int l = findSum(root->left);
        int r = findSum(root->right);
        int temp = root->data;
        root->data = l + r;
        return temp+l+r;
    }
    
    void toSumTree(Node *root)
    {
        if(!root) {
            return;
        }
        findSum(root);
    }
