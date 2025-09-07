/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node *cur=head;
        int c0=0,c1=0,c2=0;
        while(cur)
        {
            if(cur->data==0)
            {
                c0++;
                cur=cur->next;
            }
            else if(cur->data==1)
            {
                c1++;
                cur=cur->next;
            }
            else
            {
                c2++;
                cur=cur->next;
            }
        }
        cur=head;
        
        while(c0--)
        {
           cur->data=0;
           cur=cur->next;
        }
         while(c1--)
        {
           cur->data=1;
           cur=cur->next;
        }
         while(c2--)
        {
           cur->data=2;
           cur=cur->next;
        }
        return head;
    }
};