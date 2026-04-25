class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(i>maxReach) return false;
            maxReach=max(maxReach,nums[i]+i);
            if(maxReach>=n-1) return true;
        }
        return true;
    }
};
