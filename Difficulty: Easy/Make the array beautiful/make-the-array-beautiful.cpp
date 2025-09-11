// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        stack<int>s;
        for(int i=0;i<arr.size();i++)
        {
            if(s.empty())
            s.push(arr[i]);
            else if(s.top()>=0)
            {
                if(arr[i]>=0)
                s.push(arr[i]);
                else
                s.pop();
            }
            else
            {
                if(arr[i]<0)
                s.push(arr[i]);
                else
                s.pop();
            }
        }
        vector<int>ans(s.size());
        int i=ans.size()-1;
        while(!s.empty())
        {
            ans[i]=s.top();
            i--;
            s.pop();
        }
        return ans;
        
    }
};