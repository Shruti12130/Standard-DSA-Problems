int findFirstNode(Node* head)
{
        if(!head || !head->next) {
            return -1;
        }
        unordered_map<Node*, int> mp;
        Node* temp = head;
        mp[temp]++;
        while(temp->next) {
            if(mp.find(temp->next) == mp.end()) {
                mp[temp->next]++;
            } else {
                return temp->next->data;
            }
            temp = temp->next;
        }
        return -1;
}
