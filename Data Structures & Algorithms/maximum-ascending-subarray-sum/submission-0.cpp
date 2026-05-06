class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int max_Sum=nums[0];
        int current_Sum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]) current_Sum+=nums[i];
            else current_Sum=nums[i];
            if(max_Sum<current_Sum) max_Sum=current_Sum;
        }
        return max_Sum;
    }
};