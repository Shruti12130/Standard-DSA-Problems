ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* a = l1;
        ListNode* b = l2;
        ListNode* temp = new ListNode(-1), *h = temp;
        
        int carry = 0;
        while(a || b || carry) {
            int sum = carry;
            if(a) {
                sum += a->val;
                a = a->next;
            }
            if(b) {
                sum += b->val;
                b = b->next;
            }
            temp->next = new ListNode(sum%10);
            carry = sum/10;
            temp = temp->next;
        }
        
        return h->next;
}