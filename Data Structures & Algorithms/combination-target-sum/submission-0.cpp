class Solution {
public:
    vector<vector<int>> result;
    void backtrack(int idx,int target,vector<int>& path,vector<int>& nums){
        if(target==0){
            result.push_back(path);
            return;
        }
        if(target<0 || idx==nums.size()) return ;
        path.push_back(nums[idx]);
        backtrack(idx,target-nums[idx],path,nums);
        path.pop_back();
        backtrack(idx+1,target,path,nums);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> path;
        backtrack(0,target,path,nums);
        return result;
        
    }
};
