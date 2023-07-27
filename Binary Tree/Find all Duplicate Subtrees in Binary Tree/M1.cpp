vector<TreeNode*> ans;
    unordered_map<string, int> mp;
    
    string serialize(TreeNode* root) {
        if(!root) {
            return "";
        }
        string serial = to_string(root->val) + "," + serialize(root->left) + "," + 
                        serialize(root->right);
        if(mp[serial] == 1) {
            ans.push_back(root);
        }
        mp[serial]++;
        return serial;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return ans;
    }
