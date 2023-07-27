unordered_map<Node*, int> mp;
    int getMaxSum(Node *root) 
    {
        if(!root) {
            return 0;
        }
        if(mp.find(root) != mp.end()) {
            return mp[root];
        }
        
        int sum = root->data;
        if(root->left) {
            sum += getMaxSum(root->left->left);
            sum += getMaxSum(root->left->right);
        }
        if(root->right) {
            sum += getMaxSum(root->right->left);
            sum += getMaxSum(root->right->right);
        }
        
        int other = getMaxSum(root->left)+getMaxSum(root->right);
        mp[root] = max(other, sum);
        return mp[root];
    }
