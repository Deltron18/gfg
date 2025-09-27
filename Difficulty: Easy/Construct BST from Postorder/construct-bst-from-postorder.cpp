/*struct Node
{
    int data;
    Node *left, *right;
};*/

Node *bst(int post[],int &index,int lower,int upper)
{
    if((index==-1) || (post[index]<lower) || (post[index]>upper))
    return NULL;
    
    Node *root=new Node(post[index--]);
    root->right=bst(post,index,root->data,upper);
    root->left=bst(post,index,lower,root->data);
    return root;
}

Node *constructTree(int post[], int size) {
    // code here
    int index=size-1;
    return bst(post,index,INT_MIN,INT_MAX);
    
}