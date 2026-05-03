class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[26]={0};
        for(auto c:text) freq[c-'a']++;
        int b=freq['b'-'a']/1;
        int a=freq['a'-'a']/1;
        int l=freq['l'-'a']/2;
        int o=freq['o'-'a']/2;
        int n=freq['n'-'a']/1;
        return min({b,a,l,o,n});
    }
};