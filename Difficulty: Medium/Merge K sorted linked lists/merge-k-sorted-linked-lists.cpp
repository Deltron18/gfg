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
     Node *merge(Node*h1,Node *h2)
     {
         Node *head=new Node(0);
         Node *tail=head;
         while(h1&&h2)
         {
             if(h1->data<=h2->data)
             {
                 tail->next=h1;
                 tail=tail->next;
                 h1=h1->next;
                 tail->next=NULL;
             }
             else
             {
                  tail->next=h2;
                 tail=tail->next;
                 h2=h2->next;
                 tail->next=NULL;
             }
             if(h1)
             {
                 tail->next=h1;
             }
             else
             tail->next=h2;
         }
         return head->next;
     }
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        Node *head=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            head=merge(head,arr[i]);
        }
        return head;
    }
};