/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    Node *deleteNode(Node *root, int x) {
        // code here
        if(!root)
        return NULL;
        
        if(root->data>x)
        {root->left=deleteNode(root->left,x);
        return root;}
        else if(root->data<x)
        {
            root->right=deleteNode(root->right,x);
            return root;
        }
        else
        {
            if(!root->right && !root->left)
            {
                delete root;
                return NULL;
            }
            else if(!root->right)
            {
                Node *temp=root->left;
                delete root;
                return temp;
            }
            else if(!root->left)
            {
                Node *temp=root->right;
                delete root;
                return temp;
            }
            else
            {
                Node *parent=root;
                Node *child=root->left;
                
                while(child->right)
                {
                    parent=child;
                    child=child->right;
                }
                if(root !=parent)
                {
                    parent->right=child->left;
                    child->left=root->left;
                    child->right=root->right;
                    delete root;
                    return child;
                }
                else
                {
                    child->right=root->right;
                    delete root;
                    return child;
                }
            }
        }
    }
};