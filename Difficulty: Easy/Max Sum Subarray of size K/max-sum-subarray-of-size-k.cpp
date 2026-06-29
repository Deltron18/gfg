class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int low=0,high=k-1,sum=0,res=0;
        for(int i=low;i<=high;i++){
            sum+=arr[i];
        }
        while(high<arr.size()){
            res=max(res,sum);
            low=low+1;
            high=high+1;
            if(high==arr.size())
            break;
            sum+=arr[high];
            sum-=arr[low-1];
        }
        return res;
    }
};