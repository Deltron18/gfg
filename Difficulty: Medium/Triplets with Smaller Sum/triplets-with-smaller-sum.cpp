class Solution {
  public:
    int countTriplets(int sum, vector<int>& arr) {
        // code here
        int n=arr.size(),count=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                if(arr[i]+arr[j]+arr[k]==sum)
                k--;
                else if(arr[i]+arr[j]+arr[k]<sum){
                    count+=(k-j);
                    j++;
                    
                }
                else
                k--;
            }
        }
        return count;
    }
};