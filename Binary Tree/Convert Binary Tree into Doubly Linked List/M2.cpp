Node* ans=NULL, *temp=NULL;
    void inorder(Node* root)
    {
        if(!root)
            return;
            
        inorder(root->left);
        if(!temp){
            temp=root;
            ans=temp;
        }else{
            temp->right=root;
            root->left=temp;
            temp=root;
        }
        inorder(root->right);
    }
    
    Node * bToDLL(Node *root)
    {
        // your code here
        if(!root)  return NULL;
        
        inorder(root);
        return ans;
    }
