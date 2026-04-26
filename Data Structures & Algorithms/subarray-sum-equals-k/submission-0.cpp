class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixCount;
        prefixCount[0]=1;
        int currentsum=0;
        int count =0;
        for(int num:nums){
            currentsum+=num;
            if(prefixCount.find(currentsum-k) != prefixCount.end()){
                count+=prefixCount[currentsum-k];
            }
            prefixCount[currentsum]++;
        }
        return count;

    }
};