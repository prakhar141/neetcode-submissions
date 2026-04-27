class Solution {
public:
    bool backtrack(vector<int>& nums,int idx,vector<int>&buckets,int target){
        if(idx==nums.size()){
            return true;
        }
        int curr=nums[idx];
        for(int i=0;i<buckets.size();i++){
            if(buckets[i]+curr>target) continue;
            if(i>0&& buckets[i]==buckets[i-1]) continue;
            buckets[i]+=curr;
            if(backtrack(nums,idx+1,buckets,target)) return true;
            buckets[i]-=curr;
            if(buckets[i]==0) break;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total%k!=0){
            return false;
        }
        int target=total/k;
        sort(nums.rbegin(),nums.rend());
        if(nums[0]>target) return false;
        vector<int> buckets(k,0);
        return backtrack(nums,0,buckets,target);
        
    }
};