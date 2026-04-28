class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        if(s[n-1]!='0') return false;
        vector<int> dp(n,0);
        dp[0]=1;
        vector<int> pre(n,0);
        pre[0]=1;
        for(int i=1;i<n;i++){
            int l=max(0,i-maxJump);
            int r=i-minJump;
            if(s[i]=='0' && r>=0){    
                int countReachable=pre[r]-(l>0 ? pre[l-1]:0); 
                if(countReachable>0) dp[i]=1;         
            }
            pre[i]=pre[i-1]+dp[i];
        }
        return dp[n-1]==1;
    }
};