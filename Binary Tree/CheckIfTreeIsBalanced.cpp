int checkAvl(Node* root) {
        if(!root) {
            return 0;
        }
        
        int lh = checkAvl(root->left);
        if(lh==-1) {
            return -1;
        }
        int rh = checkAvl(root->right);
        if(rh==-1) {
            return -1;
        }
        if(abs(lh-rh)>1){
            return -1;
        }
        
        return 1 + max(lh, rh);
    }
    
    bool isBalanced(Node *root)
    {
        if(!root){
            return 1;
        }
        
        if(checkAvl(root) == -1){
            return 0;
        }
        return 1;
    }
