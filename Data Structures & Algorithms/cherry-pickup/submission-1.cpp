class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,INT_MAX)));
        dp[0][0][0]=grid[0][0];
        for(int k=1;k<=2*(n-1);k++){
            for(int r1=max(0,k-(n-1));r1<=min(n-1,k);r1++){
                int c1=k-r1;
                for(int r2=max(0,k-(n-1));r2<=min(n-1,k);r2++){
                    int c2=k-r2;
                    if(grid[r1][c1]==-1 || grid[r2][c2]==-1){
                        dp[r1][c1][r2]=INT_MIN;
                        continue;
                    }
                    int best=INT_MIN;
                    if(r1>0 && r2>0){
                        best=max(best,dp[r1-1][c1][r2-1]);
                    }
                    if(r1>0 && c2>0){
                        best=max(best,dp[r1-1][c1][r2]);
                    }
                    if(c1>0 && r2>0){
                        best=max(best,dp[r1][c1-1][r2-1]);
                    }
                    if(c1>0 && c2>0){
                        best=max(best,dp[r1][c1-1][r2]);
                    }
                    if(best==INT_MIN){
                        dp[r1][c1][r2]=INT_MIN;
                        continue;
                    }
                    int cherries=grid[r1][c1];
                    if(r1!=r2){
                        cherries+=grid[r2][c2];
                    }
                    dp[r1][c1][r2]=best+cherries;
                }
            }
        }
        return max(0,dp[n-1][n-1][n-1]);
    }
};