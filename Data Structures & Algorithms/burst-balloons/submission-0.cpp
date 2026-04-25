class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int> val(n+2,1);
        for(int i=0;i<n;i++){
            val[i+1]=nums[i];
        }
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int gap=2;gap<=n+1;gap++){
            for(int left=0;left+gap<=n+1;left++){
                int right=left+gap;
                for(int k=left+1;k<right;k++){
                    int coins=val[left]*val[k]*val[right]+dp[left][k]+dp[k][right];
                    dp[left][right]=max(dp[left][right],coins);
                }

            }  
        }      
        
        return dp[0][n+1];
    }
};
