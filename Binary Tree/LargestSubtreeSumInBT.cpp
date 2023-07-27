int findMaxSum(Node* root, int &maxi) {
        if(!root) {
            return 0;
        }
        
        int l = findMaxSum(root->left, maxi);
        int r = findMaxSum(root->right, maxi);
        int sum = root->data+l+r;
        maxi = max(maxi, sum);
        return sum;
    }
    
    int findLargestSubtreeSum(Node* root)
    {
        //Write your code here
        if(!root) {
            return 0;
        }
        int mx = INT_MIN;
        int sum = findMaxSum(root, mx);
        return mx;
    }
