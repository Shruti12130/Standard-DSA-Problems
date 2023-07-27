Node* findIntersection(Node* head1, Node* head2)
{
    Node* a = head1, *b = head2;
    Node* newLL = new Node(-1);
    Node* temp = newLL;
    while(a && b) {
        if(a->data == b->data) {
            temp->next = new Node(a->data);
            a = a->next;
            b = b->next;
            temp = temp->next;
        } else if(a->data < b->data) {
            a = a->next;
        } else {
            b = b->next;
        }
    }
    
    return newLL->next;
}
