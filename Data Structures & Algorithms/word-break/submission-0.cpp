class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(const string& word:wordDict){
                int len=word.size();
                if(i<len) continue;
                if(dp[i-len] && s.substr(i-len,len)==word){
                    dp[i]=true;
                    break;
                }
            }
            
        }
        return dp[n];
    }
};
