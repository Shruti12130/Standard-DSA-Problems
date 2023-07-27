void removeLoop(Node* head)
    {
       if(!head || !head->next) {
            return;
        }
        unordered_map<Node*, int> mp;
        Node* temp = head;
        mp[temp]++;
        while(temp->next) {
            if(mp.find(temp->next)==mp.end()){
                mp[temp->next]++;
            } else {
                temp->next = NULL;
                return;
            }
            temp = temp->next;
        }
}