/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
    
    int burn(Node* root, int target, int &timer) {
        if (!root) return 0;
        
        // If this node is the target, compute heights of its children
        // so we account for burning downwards from the target.
        if (root->data == target) {
            int left = burn(root->left, target, timer);   // returns height of left subtree
            int right = burn(root->right, target, timer); // returns height of right subtree
            timer = max(timer, max(left, right));         // time to burn deepest side
            return -1;                                    // signal: target found at distance 0
        }
         
        int left = burn(root->left, target, timer);
        int right = burn(root->right, target, timer);
        
        if (left < 0) {
            // target was in left subtree; left is negative distance-to-target
            timer = max(timer, abs(left) + right);
            return left - 1;   // propagate distance-to-target upward
        }
        if (right < 0) {
            // target was in right subtree
            timer = max(timer, left + abs(right));
            return right - 1;
        }
        
        // neither subtree has target: return height
        return 1 + max(left, right);
    }
    
  public:
    int minTime(Node* root, int target) {
        int timer = 0;
        burn(root, target, timer);
        return timer;
    }
};
