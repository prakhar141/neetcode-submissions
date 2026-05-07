class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> store;
        int count=0;
        for(auto word:words){
            for(char c:word){
                store[c]++;
            }
            
        }
        for(auto pair: store){
            if(pair.second%words.size()!=0) return false;
        }
        return true;

    }
};