/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* head) {

        // code here
        Node * prev=head,*cur=head->next;
        while(cur)
        {
            if(cur->data==prev->data)
            {
                prev->next=cur->next;
                delete cur;
                cur=prev->next;
            }
            else
            {
                prev=cur;
                cur=cur->next;
            }
        }
        return head;
    }
};