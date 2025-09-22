/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
    void find(Node*root,int pos,int &l)
    {
        if(!root)
        return;
        
        l=max(l,pos);
        find(root->left,pos+1,l);
        find(root->right,pos,l);
    }
    
    void finddia(Node*root,int pos,vector<vector<int>>&ans)
    {
        if(!root)
        return;
        
        ans[pos].push_back(root->data);
        finddia(root->left,pos+1,ans);
        finddia(root->right,pos,ans);
    }
    
  public:
    vector<int> diagonal(Node *root) {
        // code here
        int l=0;
        find(root,0,l);
        vector<vector<int>>ans(l+1);
        finddia(root,0,ans);
        vector<int>temp;
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<ans[i].size();j++)
            {
                temp.push_back(ans[i][j]);
            }
        }
        return temp;
    }
};