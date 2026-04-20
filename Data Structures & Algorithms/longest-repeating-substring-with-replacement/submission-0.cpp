class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int maxfreq=0;
        int answer=0;
        int count[26]={0};
        for (int right=0;right < s.size();right++){
            count[s[right]-'A']++;
            maxfreq=max(maxfreq,count[s[right]-'A']);
            if((right-left+1)-maxfreq>k){
                count[s[left]-'A']--;
                left++;
            }
            answer=max(answer,right-left+1);
        }
        return answer;

    }
};
