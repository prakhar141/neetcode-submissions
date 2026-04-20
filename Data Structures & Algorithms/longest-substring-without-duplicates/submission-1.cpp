class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int maxlength=0;
        int count[128]={0};
        for(int right=0;right<s.size();right++){
            count[s[right]]++;
            while(count[s[right]]>1){
                count[s[left]]--;
                left++;
            }
            maxlength=max(maxlength,right-left+1);
        }
        return maxlength;
        
    }
};
