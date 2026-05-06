class Solution {
public:
    int Find_At_Most_K(vector<int>& nums,int k){
        int left_edge=0;
        int total_count=0;
        unordered_map<int,int> tally;
        for(int i=0;i<nums.size();i++){
            tally[nums[i]]++;
            while(tally.size()>k){
                tally[nums[left_edge]]--;
                if(tally[nums[left_edge]]==0) tally.erase(nums[left_edge]);
                left_edge++;
            }
            total_count+=(i-left_edge+1);
        }
        return total_count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return(Find_At_Most_K(nums,k)-Find_At_Most_K(nums,k-1));
        
    }
};