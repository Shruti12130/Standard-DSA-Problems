Node* lca(Node* root ,int n1 ,int n2 )
    {
        if(!root) {
            return NULL;
        }
        if(root->data == n1 || root->data == n2) {
            return root;
        }
        
        Node* left = lca(root->left, n1, n2);
        Node* right = lca(root->right, n1, n2);
        if(left == NULL) {
            return right;
        } else if (right == NULL) {
            return left;
        } else {
            return root;
        }
       
    }
    
    int findDistance(Node* root, int key) {
        if(!root || (!root->left && !root->right && root->data != key)) {
            return 0;
        }
        if(root->data == key) {
            return 1;
        } 
        int l = findDistance(root->left, key);
        int r = findDistance(root->right, key);
        
        if(l || r) {
            return 1+max(l, r);
        } else {
            return 0;
        }
        
    }
    
    int findDist(Node* root, int a, int b) {
        if(!root) {
            return 0;
        }
        Node* commonAncestor = lca(root, a, b);
        int nodeDist = findDistance(root, commonAncestor->data);
        int dista = findDistance(root, a);
        int distb = findDistance(root, b);
        
        int minSum = dista+distb-2*nodeDist;
        return minSum;
    }
