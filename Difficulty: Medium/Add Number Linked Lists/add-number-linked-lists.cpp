class Solution {
  public:
  Node *reverse(Node *cur, Node *prev){
       if(cur == NULL) return prev;
       Node *fut = cur->next;
       cur->next = prev;
       return reverse(fut, cur);
   }
   
    Node* trimZeros(Node* head) {
        // remove leading zeros but keep at least one digit
        while(head && head->data == 0 && head->next) {
            head = head->next;
        }
        return head;
    }

    Node* addTwoLists(Node* head1, Node* head2) {
        // Reverse both lists
        head1 = reverse(head1, NULL);
        head2 = reverse(head2, NULL);

        Node* cur1 = head1;
        Node* cur2 = head2;
        Node* head = new Node(0);  // dummy head
        Node* tail = head;
        int carry = 0;

        // Add while both lists have nodes
        while(cur1 && cur2) {
            int sum = cur1->data + cur2->data + carry;
            tail->next = new Node(sum % 10);
            tail = tail->next;
            cur1 = cur1->next;
            cur2 = cur2->next;
            carry = sum / 10;
        }

        // Remaining nodes of list1
        while(cur1) {
            int sum = cur1->data + carry;
            tail->next = new Node(sum % 10);
            tail = tail->next;
            cur1 = cur1->next;
            carry = sum / 10;
        }

        // Remaining nodes of list2
        while(cur2) {
            int sum = cur2->data + carry;
            tail->next = new Node(sum % 10);
            tail = tail->next;
            cur2 = cur2->next;
            carry = sum / 10;
        }

        // Remaining carry
        while(carry) {
            tail->next = new Node(carry % 10);
            tail = tail->next;
            carry /= 10;
        }

        // Reverse result
        head = reverse(head->next, NULL);

        // Trim leading zeros
        head = trimZeros(head);

        return head;
    }
};
