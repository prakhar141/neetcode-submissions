class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int n=nums.size();
      int currMax=nums[0];
      int currMin=nums[0];
      int result=nums[0];
      for(int i=1;i<n;i++){
        int x=nums[i];
        int prevMax=currMax;
        int prevMin=currMin;
        currMax=max(x,max(prevMax*x,prevMin*x));
        currMin=min(x,min(prevMax*x,prevMin*x));
        result=max(currMax,result);
      }  
      return result;
    }
};
