class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF=amount+1;
        vector <int> dp(amount+1,INF);
        dp[0]=0;
        for(int a=1;a<=amount;a++){
            for(int c:coins){
                if(c>a) continue;
                dp[a]=min(dp[a],1+dp[a-c]);
            }
        }
        return dp[amount]==INF ? -1:dp[amount];
    }
};
