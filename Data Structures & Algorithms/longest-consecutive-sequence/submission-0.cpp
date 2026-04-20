class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }
        unordered_set<int> box(nums.begin(),nums.end());
        int longest=0;
        for (int num:box){
            if (box.find(num-1)==box.end()){
                int currentNum=num;
                int currentStreak=1;
                while(box.find(currentNum+1)!=box.end()){
                    currentNum+=1;
                    currentStreak+=1;
                }
                if(currentStreak>longest){
                    longest=currentStreak;
                }
            }
        }
        return longest;
    }
};
