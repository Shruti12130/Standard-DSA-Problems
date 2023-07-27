vector<int> ans;
    
    void leftBoundary(Node* root) {
        //if node is NULL or leaf, then RETURN
        if(!root || (!root->left && !root->right)) {     
            return;
        }
        ans.push_back(root->data);
        if(root->left) {
            leftBoundary(root->left);
        } else {
            leftBoundary(root->right);
        }
    }
    
    void leaves(Node* root) {
        if(!root) {
            return;
        }
        if(!root->left && !root->right) {
            ans.push_back(root->data);
        }
        leaves(root->left);
        leaves(root->right);
    }
    
    void rightBoundary(Node* root) {
        if(!root || (!root->left && !root->right)) {
            return;
        }
        if(root->right) {
            rightBoundary(root->right);
        } else {
            rightBoundary(root->left);
        }
        ans.push_back(root->data);
    }
        
    vector <int> boundary(Node *root)
    {
        if(!root) {
            return ans;
        }
        //If the root is not a leaf node
        if(root->left || root->right) {
            ans.push_back(root->data);
        }
        leftBoundary(root->left);
        leaves(root);
        rightBoundary(root->right);
        return ans;
    }
