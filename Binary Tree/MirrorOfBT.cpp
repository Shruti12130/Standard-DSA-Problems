void mirror(Node* root) {
        if(!root) {
            return;
        }
        Node* left = root->left;
        Node* right = root->right;
        
        root->right = left;
        root->left = right;
        
        mirror(root->left);
        mirror(root->right);
}
