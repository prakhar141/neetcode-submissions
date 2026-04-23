class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;
    void backtrack(int i,vector<int>& nums,vector<int>& current){
        if (i==nums.size()){
            result.push_back(current);
            return;
        }
        current.push_back(nums[i]);
        backtrack(i+1,nums,current);
        current.pop_back();
        backtrack(i+1,nums,current);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        result.clear();
        backtrack(0,nums,current);
        return result;

        
    }
};
