void findMaxSum(Node* root, int height, int &maxHeight, int sum, int &maxi) {
        if(!root) {
            if(height > maxHeight) {
                maxHeight = height;
                maxi = sum;
            } else if(height == maxHeight){
                maxi = max(maxi, sum);
            }
            return;
        }
        findMaxSum(root->left, height+1, maxHeight, sum+root->data, maxi);
        findMaxSum(root->right, height+1, maxHeight, sum+root->data, maxi);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        if(!root) {
            return 0;
        }
        int mx = INT_MIN;
        int ht = 0, maxh = 0;
        findMaxSum(root, ht, maxh, 0, mx);
        return mx;
    }
