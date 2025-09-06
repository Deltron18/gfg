/* Link list Node

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */
class Solution {
  public:
    Node* deleteK(Node* head, int k) {
        // code here
        if(k==1)
        return NULL;
        
        Node *cur=head, *prev=NULL;
        int count=1;
        
        while(cur){
            if(count==k){
                prev->next=cur->next;
                delete cur;
                cur=prev->next;
                count=1;
            }
            else{
                prev=cur;
                cur=cur->next;
                count++;
            }
        }
        return head;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};