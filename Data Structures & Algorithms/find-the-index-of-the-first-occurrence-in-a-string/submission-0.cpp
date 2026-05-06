class Solution {
public:
    int strStr(string haystack, string needle) {
        int index=haystack.find(needle);
        if(index==std::string::npos) return -1;
        return index;
    }
};