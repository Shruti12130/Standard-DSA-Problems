vector<int> diagonal(Node *root)
{
   vector<int> ans;
   if(!root) {
       return ans;
   }
   queue<Node*> q;
   q.push(root);
   
   while(!q.empty()) {
       int size = q.size();
       vector<int> temp;
       while(size--) {
           Node* node = q.front();
           q.pop();
           while(node) {
               temp.push_back(node->data);
               if(node->left) {
                   q.push(node->left);
               }
               node = node->right;
           }
       }
       ans.insert(ans.end(), temp.begin(), temp.end());
   }
   return ans;
}

//Method-2

vector<int> diagonal(Node *root)
{
   vector<int> ans;
   if(!root) {
       return ans;
   }
   queue<Node*> leftQ;
   Node* node = root;
   
   while(node) {
       ans.push_back(node->data);
       if(node->left) {
           leftQ.push(node->left);
       }
       if(node->right) {
           node = node->right;
       } else {
           //if there's no further right node, move onto the earliest encountered left node
           if(!leftQ.empty()) {
               node = leftQ.front();
               leftQ.pop();
           } else {
               node = NULL;
           }
       }
   }
   return ans;
}
