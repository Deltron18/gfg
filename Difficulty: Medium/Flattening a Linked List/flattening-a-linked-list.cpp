/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
     Node *merge(Node*h1,Node *h2)
     {
         Node *head=new Node(0);
         Node *tail=head;
         while(h1&&h2)
         {
             if(h1->data<=h2->data)
             {
                 tail->bottom=h1;
                 tail=tail->bottom;
                 h1=h1->bottom;
                 tail->bottom=NULL;
             }
             else
             {
                  tail->bottom=h2;
                 tail=tail->bottom;
                 h2=h2->bottom;
                 tail->bottom=NULL;
             }
             if(h1)
             {
                 tail->bottom=h1;
             }
             else
             tail->bottom=h2;
         }
         return head->bottom;
     }
  public:
    Node *flatten(Node *root) {
        // code here
        Node *h1,*h2,*h3;
        while(root->next)
        {
             h1=root;
        h2=root->next;
        h3=root->next->next;
        
        h1->next=NULL;
        h2->next=NULL;
        root=merge(h1,h2);
        root->next=h3;
        }
       return root;
    }
};