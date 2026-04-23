class Solution {
public:
void dfs(vector<vector<char>>& grid,int r,int c){
    int row=grid.size();
    int col=grid[0].size();
    if(r<0 || c<0||r>=row|| c>=col||grid[r][c]!='1') return;
    grid[r][c]='0';
    dfs(grid,r+1,c);
    dfs(grid,r-1,c);
    dfs(grid,r,c+1);
    dfs(grid,r,c-1);
}
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int cols=grid[0].size();
        int rows=grid.size();
        int count=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
        
    }
};
