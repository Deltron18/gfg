// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
  public:
    vector<int> inOrder(Node* root) {
        // code here
        stack<Node*>s;
        stack<bool>v;
        s.push(root);
        v.push(0);
        vector<int>ans;
        while(!s.empty())
        {
            Node*temp=s.top();
            s.pop();
            bool flag=v.top();
            v.pop();
            if(flag==0)
            {
                if(temp->right)
                {s.push(temp->right);
                v.push(0);}
                s.push(temp);
                v.push(1);
                if(temp->left)
                {s.push(temp->left);
                v.push(0);}
            }
            else
            {
                ans.push_back(temp->data);
            }
        }
        return ans;
    }
};