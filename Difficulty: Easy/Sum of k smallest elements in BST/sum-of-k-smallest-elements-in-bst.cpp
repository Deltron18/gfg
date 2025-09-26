// User function Template for C++

/*
struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/

// Function to find ceil of a given input in BST. If input is more
// than the max key in BST, return -1

void ksum(Node* root, int &k, int &sum )
{
    if(!root || k<=0)
    return ;
    
    ksum(root->left,k,sum);
    k--;
    if(k>=0)
    sum+=root->data;
    if(k<=0)
    return;
    ksum(root->right,k,sum);
}
int sum(Node* root, int k) {

    // Your code here
    int sum=0;
    ksum(root,k,sum);
    return sum;
    
}