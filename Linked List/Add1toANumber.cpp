Node* reverse(Node* head) {
        Node* prev = NULL, *curr = head, *next;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    Node* addOne(Node *head) 
    {
        Node* temp = reverse(head);
        Node* a = temp;
        
        int carry = 1;
        while(temp) {
            int sum = temp->data + carry;
            temp->data = sum%10;
            carry = sum/10;
            temp = temp->next;
        }
        Node* t = a;
        while(t->next) t=t->next;
        if(carry != 0) {
            t->next = new Node(carry);
            t = t->next;
        }
        
        return reverse(a);
}