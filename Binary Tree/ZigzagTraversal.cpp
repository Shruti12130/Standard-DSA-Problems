vector <int> zigZagTraversal(Node* root)
    {
            vector<int> ans;
            queue<Node*> q;
            q.push(root);
            bool f = 1;
            
            while(!q.empty()) {
                int size = q.size();
                vector<int> temp;
                for(int i=0;i<size;i++){
                    Node* node = q.front();
                    q.pop();
                    temp.push_back(node->data);
                    if(node->left) {
                        q.push(node->left);
                    }
                    if(node->right){
                        q.push(node->right);
                    }
                }
                if(!f) {
                    reverse(temp.begin(), temp.end());
                }
                f = !f;
                ans.insert(ans.end(), temp.begin(), temp.end());
            }
            return ans;
}
