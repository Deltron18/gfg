// class Solution {
//   public:
//     int celebrity(vector<vector<int>>& mat) {
//         // code here
//         int n= mat.size();
//         stack<int>st;
//         for(int i=n-1;i>=0;i--)
//         st.push(i);
//         while(st.size()>1)
//         {
//             int first=st.top();
//             st.pop();
//             int sec=st.top();
//             st.pop();
//             if(mat[first][sec] && !mat[sec][first])
//             st.push(sec);
//             else if(!mat[first][sec] && mat[sec][first])
//             st.push(first);
//         }
//         if(st.empty())
//         return -1;
        
//         int num=st.top();
//         st.pop();
//         int row=0,col=0;
//         for(int i=0;i<n;i++)
//         {
//             row+=mat[num][i];
//             col+=mat[i][num];
//         }
//         return (row==0 && col==n-1) ? num : -1;
//     }
// };

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        stack<int> st;

        // Push all people into stack
        for (int i = n - 1; i >= 0; i--)
            st.push(i);

        // Eliminate non-celebrities
        while (st.size() > 1) {
            int first = st.top(); st.pop();
            int sec = st.top(); st.pop();

            if (mat[first][sec] == 1) {
                // first knows sec -> first cannot be celebrity
                st.push(sec);
            } else {
                // first does not know sec -> sec cannot be celebrity
                st.push(first);
            }
        }

        if (st.empty()) return -1;

        int num = st.top(); 
        st.pop();

        int row = 0, col = 0;

        // Verify candidate
        for (int i = 0; i < n; i++) {
            if (i == num) continue; // skip self
            if (mat[num][i] == 1 || mat[i][num] == 0) {
                return -1;
            }
        }
        return num;
    }
};
