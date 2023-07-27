unordered_map<string, int> mp;
    string serialize(Node* root) {
        if(!root) {
            return "";
        }
        string serial = "";
        if(!root->left && !root->right) {
            serial += to_string(root->data);
            return serial;
        }
        serial = to_string(root->data) + "," + serialize(root->left) + "," +
                        serialize(root->right);
        mp[serial]++;
        return serial;
    }
    
    int dupSub(Node *root) {
         mp.clear();
         serialize(root);
         for(auto it: mp) {
             if(it.second > 1) {
                 return 1;
             }
         }
         return 0;
    }
