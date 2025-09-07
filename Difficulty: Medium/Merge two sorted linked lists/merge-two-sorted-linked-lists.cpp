/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* sortedMerge(Node* h1, Node* h2) {
        // code here
        Node *head=new Node(0);
        Node *tail=head;
        while(h1 && h2)
        {
            if(h1->data <= h2->data)
            {
                tail->next=h1;
                h1=h1->next;
                tail=tail->next;
                tail->next=NULL;
            }
            else
            {
                 tail->next=h2;
                h2=h2->next;
                tail=tail->next;
                tail->next=NULL;
            }
        }
        if(h1)
        tail->next=h1;
        else
        tail->next=h2;
        
        tail=head;
        head=head->next;
        delete tail;
        return head;
        
        
    }
};