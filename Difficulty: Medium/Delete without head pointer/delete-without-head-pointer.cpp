/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;
*/

class Solution {
  public:
    void deleteNode(Node* cur) {
        // code here
        Node *temp=cur->next;
        cur->data = temp->data;
        cur->next = temp->next;
        delete temp;
    }
};