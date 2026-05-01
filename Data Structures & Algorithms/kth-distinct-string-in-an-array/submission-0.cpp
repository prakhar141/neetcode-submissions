class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> freq;
        for(string& s :arr) freq[s]++;
        int distinctCount=0;
        for(string& s:arr){
            if(freq[s]==1) distinctCount++;
            if(distinctCount==k) return s;
        }
        return "";
    }
};