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

 // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) {
            return NULL;
        }
        
        //This lets us iterate through a string stream in form of objects
        stringstream s(data);
        string str;
        //This will get us the node values out of the stream each separated by a delimiter ','
        getline(s, str, ',');
        
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            getline(s, str, ',');
            if(str == "#") {
                node->left = NULL;
            } else {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }
            
            getline(s, str, ',');
            if(str == "#") {
                node->right = NULL;
            } else {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        
        return root;
    }

//METHOD - 2

 // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        if (data == "#") return NULL;
        stringstream s(data);
        return makeDeserialize(s);
    }
    
    TreeNode* makeDeserialize(stringstream& s) {
        string str;
        getline(s, str, ',');
        if (str == "#") {
            return NULL;
        } else {
            TreeNode* root = new TreeNode(stoi(str));
            root->left = makeDeserialize(s);
            root->right = makeDeserialize(s);
            return root;
        }
    }
