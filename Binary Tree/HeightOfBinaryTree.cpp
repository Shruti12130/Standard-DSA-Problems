/*
        Height is basically: for a root node: 1 + max of its left height, the right height. 
        Adding 1 because the node for which we are calculating height will also be 
        contributing for one extra level of height. 
*/

int height(struct Node* node){
        if(!node) {
            return 0;
        }
        int lh = height(node->left);
        int rh = height(node->right);
        return 1 + max(lh, rh);
}
