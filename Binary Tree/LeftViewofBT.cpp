vector<int> ans;

void solve(Node* root, int level) {
    if(!root) {
        return;
    }
    if(ans.size() == level) {
        ans.push_back(root->data);
    }
    solve(root->left, level+1);
    solve(root->right, level+1);
}

vector<int> leftView(Node *root)
{
   solve(root, 0);
   return ans;
}
