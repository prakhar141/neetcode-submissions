class Solution {
public:
    vector<vector<int>> memo;
    vector<int> suffixSum;
    int n;
    int dfs(int i,int M){
        if(i>=n) return 0;
        if(2*M>=n-i) return suffixSum[i];
        if(memo[i][M]!=-1) return memo[i][M];
        int best=0;
        for(int x=1;x<=2*M;x++){
            int opponent=dfs(i+x,max(M,x));
            best=max(best,suffixSum[i]-opponent);
        }
        return memo[i][M]=best;
    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        suffixSum.assign(n,0);
        suffixSum[n-1]=piles[n-1];
        for(int i=n-2;i>=0;i--){
            suffixSum[i]=suffixSum[i+1]+piles[i];
        }
        memo.assign(n,vector<int>(n+1,-1));
        return dfs(0,1);
        
    }
};