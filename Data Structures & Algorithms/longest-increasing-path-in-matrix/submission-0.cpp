class Solution {
private:
    int dfs(vector<vector<int>>& mat,int i,int j,vector<vector<int>>& memo){
        if(memo[i][j]!=0)return memo[i][j];
        int best=1;
        int dirs[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
        for(auto& d:dirs){
            int x=i+d[0];
            int y=j+d[1];
            if(x>=0 && x<mat.size()&& y>=0&&y<mat[0].size()&& mat[x][y]>mat[i][j]){
                best=max(best,1+dfs(mat,x,y,memo));
            }
        }
        memo[i][j]=best;
        return best;
        
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> memo(m,vector<int>(n,0));
        int result=0;
        for(int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                result=max(result,dfs(matrix,i,j,memo));
            }
        }
        return result;
    }
};
