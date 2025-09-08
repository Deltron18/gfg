/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        Node *first=new Node(0);
        first->next=head;
        head=first;
        int x;
        Node *second , *prev ,*cur,*fut;
        while(first->next)
        {
             x=k;
            second=first->next;
            prev=first;
            cur=first->next;
            while(x && cur)
            {
                fut=cur->next;
                cur->next=prev;
                prev=cur;
                cur=fut;
                x--;
            }
            first->next=prev;
            second->next=cur;
            first=second;
        }
        first=head;
        head=head->next;
        delete first;
        return head;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};