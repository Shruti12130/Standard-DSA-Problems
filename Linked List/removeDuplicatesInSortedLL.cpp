Node *removeDuplicates(Node *head)
{
    Node* temp = head;
    while(temp) {
        Node* t = temp->next;
        while(t && t->data == temp->data) {
            t = t->next;
        }
        temp->next = t;
        temp = temp->next;
    }
    return head;
}