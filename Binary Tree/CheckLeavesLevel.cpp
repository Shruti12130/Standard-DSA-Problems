int checkLeavesLevel(Node* root, int level, int& leafLevel) {
        if(!root) {
            return 0;
        }
        if(!root->left && !root->right) {
            if(leafLevel == -1) {
                leafLevel = level;
            } else if(leafLevel != level) {
                return -1;
            }
        }
        
        int l = checkLeavesLevel(root->left, level+1, leafLevel);
        if(l == -1)  return -1;
        int r = checkLeavesLevel(root->right, level+1, leafLevel);
        if(r == -1)  return -1;
        return level;
    }
    
    bool check(Node *root)
    {
        int level = 0, leafLevel = -1;
        if(checkLeavesLevel(root, level, leafLevel) == -1) {
            return 0;
        } else {
            return 1;
        }
    }
