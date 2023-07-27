vector<Node*> tree;
    void inorder(Node* root) {
        if(!root) {
            return;
        }
        inorder(root->left);
        tree.push_back(root);
        inorder(root->right);
    }
    
    Node * bToDLL(Node *root)
    {
        if(!root) {
            return root;
        }
        
        tree.push_back(NULL);
        inorder(root);
        tree.push_back(NULL);
        int n = tree.size();
        
        for(int i=1;i<n-1;i++) {
            tree[i]->left = tree[i-1];
            tree[i]->right = tree[i+1];
        }
        return tree[1];
    }
