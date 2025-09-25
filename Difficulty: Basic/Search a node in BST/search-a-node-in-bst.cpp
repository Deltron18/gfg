/*
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/
bool search(Node* root, int x) {
    // Your code here
    if(!root)
    return 0;
    
    if(root->data==x)
    return 1;
    if(root->data>x)
    return search(root->left,x);
    else
    return search(root->right,x);
}