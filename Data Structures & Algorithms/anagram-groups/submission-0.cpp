class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       //craete a map like a dict
       //key sorted word
       //value list of words that are anagrams of each other
       //  "aet" → ["eat", "tea", "ate"]
        //  "ant" → ["tan", "nat"]
        //  "abt" → ["bat"]
        unordered_map<string,vector<string>> res;
        for (const auto& s : strs){
            string SortedS=s;
            sort(SortedS.begin(),SortedS.end());
            res[SortedS].push_back(s);

        } 
        vector<vector<string>> result;
        for(auto& pair:res){
            result.push_back(pair.second);
        }
        return result;
    }
};
