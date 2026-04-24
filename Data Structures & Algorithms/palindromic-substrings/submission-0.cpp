class Solution {
private:
    int countFromCentre(const string& s,int left,int right){
        int count=0;
        while(left>=0 && right<=s.size() && s[left]==s[right]){
            count++;
            left--;
            right++;
        }
        return count;
    }
public:
    int countSubstrings(string s) {
        int n=s.size();
        int total=0;
        for(int i=0;i<n;i++){
            total+=countFromCentre(s,i,i);
            total+=countFromCentre(s,i,i+1);

        }
        return total;
    }
};
