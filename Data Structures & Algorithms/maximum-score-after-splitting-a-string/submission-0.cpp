class Solution {
public:
    int maxScore(string s) {
        int total_ones=count(s.begin(),s.end(),'1');
        int zeros_left=0;
        int ones_left=0;
        int max_score=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0') zeros_left++;
            else ones_left++;
        
            int ones_right=total_ones-ones_left;
            max_score=max(max_score,zeros_left+ones_right);
        }
        return max_score;
    }

};