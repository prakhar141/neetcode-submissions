class Solution {
private:
    int expandaroundCentre(const string& s, int left,int right){
        while(left>=0 && right<s.size()&& s[left]==s[right]){
            --left;
            ++right;
            // Formula: (right - 1) - (left + 1) + 1 = right - left - 1.
        }
        return right-left-1;
    }
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        int n=s.size();
        int start=0;
        int maxLen=0;
        for(int i=0;i<n;i++){
            int len1=expandaroundCentre(s,i,i);
            int len2=expandaroundCentre(s,i,i+1);
            int len=max(len1,len2);
            if(len>maxLen){
                maxLen=len;
                start=i-(len-1)/2;
            }
        }
        return s.substr(start,maxLen);
    }
};
