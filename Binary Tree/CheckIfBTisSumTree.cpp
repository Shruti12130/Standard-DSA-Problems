int isSum(Node* root) {
        if(!root) {
            return 0;
        }
        if(!root->left && !root->right) {
            return root->data;
        }
        
        int l = isSum(root->left);
        if(l == -1){
            return -1;
        }
        int r = isSum(root->right);
        if(r == -1) {
            return -1;
        }
        int temp = root->data;
        if(root->data != l+r) {
            return -1;
        }
        return root->data + l + r;
    }
    
    bool isSumTree(Node* root)
    {
         // Your code here
         if(isSum(root) == -1) {
             return 0;
         } else {
             return 1;
         }
    }
