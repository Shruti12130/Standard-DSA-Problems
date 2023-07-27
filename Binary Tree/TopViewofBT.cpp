vector<int> topView(Node *root)
    {
        vector<int> ans;
        queue<pair<Node*, int>> q;
        map<int, Node*> mp;
        
        q.push({root, 0});
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            Node* node = temp.first;
            int line = temp.second;
            mp.insert({line, node});
            
            if(node->left) {
                q.push({node->left, line-1});
            }
            if(node->right) {
                q.push({node->right, line+1});
            }
        }
        
        for(auto it: mp) {
            ans.push_back(it.second->data);
        }
        return ans;
}
