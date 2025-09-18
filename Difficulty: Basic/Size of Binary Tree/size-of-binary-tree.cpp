/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
    
    void total(Node * root,int &count)
    {
        if(root == NULL)
        return;
        count++;
        total(root->left,count);
        total(root->right,count);
    }
    
  public:
    int getSize(Node* root) {
        // code here
        int count=0;
        total(root,count);
        return count;
    }
};