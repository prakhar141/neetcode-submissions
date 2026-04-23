class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0;
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(grid[r][c]==2) q.push({r,c});
                else if(grid[r][c]==1) fresh++;
            }
        }
        if(fresh==0) return 0;
        int minutes=0;
        vector<pair<int,int>> dirs={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int size=q.size();
            bool rottedThisMinute= false;
            for(int i=0;i<size;i++){
                auto[r,c]=q.front();
                q.pop();
                for(auto [dr,dc]:dirs){
                    int nr=r+dr;
                    int nc=c+dc;
                    if(nr<0||nr>=row||nc<0||nc>=col) continue;
                    if(grid[nr][nc]!=1) continue;
                    grid[nr][nc]=2;
                    fresh--;
                    q.push({nr,nc});
                    rottedThisMinute=true;
                }
            }
            if(rottedThisMinute) minutes++;
        }
        return fresh==0?minutes:-1;
    }
};
