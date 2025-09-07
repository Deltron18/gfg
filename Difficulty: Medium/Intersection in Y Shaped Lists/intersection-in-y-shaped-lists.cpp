/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        Node *cur1 = head1, *cur2 = head2;
        int c1 = 0, c2 = 0;

        // count length of list1
        while (cur1) {
            c1++;
            cur1 = cur1->next;
        }

        // count length of list2
        while (cur2) {
            c2++;
            cur2 = cur2->next;
        }

        cur1 = head1;
        cur2 = head2;

        // move longer list's pointer ahead
        while (c1 > c2) {
            cur1 = cur1->next;
            c1--;
        }
        while (c2 > c1) {
            cur2 = cur2->next;
            c2--;
        }

        // traverse both lists
        while (cur1 && cur2) {
            if (cur1 == cur2)  // intersection found
                return cur1;   // ✅ return the node itself
            cur1 = cur1->next;
            cur2 = cur2->next;
        }

        return NULL;  // no intersection
    }
};
