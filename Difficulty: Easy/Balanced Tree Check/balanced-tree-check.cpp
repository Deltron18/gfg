/*

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
 */

class Solution {
    
    int height(Node* root , int &valid)
    {
        if(!root)
        return -1;
        
        int l = height(root->left,valid);
        int r = height(root->right,valid);
        
        if(abs(l-r)>1)
        valid= 0;
        
        return 1+max(l,r);
    }
    
  public:
    bool isBalanced(Node* root) {
        // Code here
        int valid=1;
        height(root,valid);
        return valid;
    }
};