Node * removeDuplicates( Node *head) {
        Node* temp = head;
        unordered_set<int> s;
        
        while(temp) {
            Node* t = temp;
            s.insert(t->data);
            while(t && s.find(t->data) != s.end()) {
                t = t->next;
            }
            temp->next = t;
            temp = temp->next;
        }
        return head;
}