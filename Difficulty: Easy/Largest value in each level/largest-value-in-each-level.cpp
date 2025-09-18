// User function Template for C++

class Solution {
  public:
    vector<int> largestValues(Node* root) {
        vector<int> res;
        if (!root) return res;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            int levelMax = INT_MIN;
            
            for (int i = 0; i < n; i++) {
                Node* temp = q.front();
                q.pop();
                
                levelMax = max(levelMax, temp->data);
                
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            res.push_back(levelMax);
        }
        
        return res;
    }
};