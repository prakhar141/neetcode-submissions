class Solution {
public:
    unordered_map<int,vector<string>> memo;
    unordered_set<string>dict;
    
    vector<string> solve(const string& s,int start){
        if(memo.count(start)) return memo[start];
        vector<string> result;
        if(start==s.size()){
            result.push_back("");
            return result;
        }
        for(int end=start+1;end<=s.size();end++){
            string word=s.substr(start,end-start);
            if(dict.count(word)){
                vector<string> suffixSentences=solve(s,end);
                for(const string& sub:suffixSentences){
                    result.push_back(word+(sub.empty()?"":" "+sub));
                }
            }
        }
        return memo[start]=result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        memo.clear();
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        
        
        return solve(s,0);
        
    }
};