class Solution {
  public:
    int smallestSumSubarray(vector<int>& arr) {
        // Code here
        int bestend= arr[0],ans=arr[0];
        for(int i=1;i<arr.size();i++){
            int v1= arr[i];
            int v2=bestend+arr[i];
            
            bestend=min(v1,v2);
            
            ans=min(ans,bestend);
        }
        return ans;
    }
};
