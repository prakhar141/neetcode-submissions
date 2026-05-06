class Solution {
public:
    int firstUniqChar(string s) {
        int count=0;
        unordered_map<char,int> store;
        for(int i=0;i<s.size();i++){
            store[s[i]]++;
        }
        for(int i=0;i<s.size();i++){
            if(store[s[i]]==1) return i;
        }
        return -1;
    }
};