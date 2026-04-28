class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total=0;
        int curMax=0;
        int maxSum=nums[0];
        int curMin=0;
        int minSum=nums[0];
        for(int x:nums){
            curMax=max(curMax+x,x);
            maxSum=max(curMax,maxSum);
            curMin=min(curMin+x,x);
            minSum=min(curMin,minSum);
            total+=x;
        }
        if(maxSum<0) return maxSum;
        return max(maxSum,total-minSum);
    }
};