/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
    
    void large(Node *root, int &k,int &ans){
        if(!root)
        return ;
        
        large(root->right,k,ans);
        k--;
        if(k==0)
        ans=root->data;
        if(k<=0)
        return;
        large(root->left,k,ans);
    }
    
  public:
    int kthLargest(Node *root, int k) {
        // Your code here
        int ans=0;
        large(root,k,ans);
        return ans;
    }
};