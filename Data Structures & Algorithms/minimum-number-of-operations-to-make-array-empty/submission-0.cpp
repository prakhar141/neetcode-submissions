#include<vector>
#include<unordered_map>
class Solution {
public:
    int minOperations(vector<int>& nums) {
        std::unordered_map<int,int> counts;
        for(int num:nums){
            counts[num]++;
        }
        int total_operations=0;
        for(auto const&[num,count]:counts){
            if(count==1) return -1;
        
           total_operations+=(count+2)/3;
        }
        return total_operations;

        
    }
};