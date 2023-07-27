//Using hashing
//Here we will chech if the node we have visisted is present or not if we have visited it then it mean there is cycle.
//Time complexity: O(n)          Space complexity: O(n)

    unordered_map<ListNode*,int> mp;
    bool hasCycle(ListNode *head) {
        while(head!=NULL){
            if(mp.find(head) == mp.end()){
                mp[head]++;
            }
            else{
                return true;
            }
            head=head->next;
        }
        return false;
}