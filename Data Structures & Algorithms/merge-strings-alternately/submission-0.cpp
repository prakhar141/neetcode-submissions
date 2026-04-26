class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int n1=word1.size();
        int n2=word2.size();
        int i=0;
        result.reserve(n2);
        while(i<n1 && i<n2){
            result+=word1[i];
            result+=word2[i];
            i++;
        }
        while(i<n1){
            result+=word1[i];
            i++;;
        }
        while(i<n2){
            result+=word2[i];
            i++;
        }
        return result;
    }
};