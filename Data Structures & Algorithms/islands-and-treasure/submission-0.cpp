class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        const int INF=2147483647;
        queue<pair<int,int>> q;
        for(int r=0;r<m;r++){
            for (int c=0;c<n;c++){
                if(grid[r][c]==0) q.push({r,c});

            }
        }
        vector<pair<int,int>> dirs={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();
            for(auto[dr,dc]:dirs){
                int nr=r+dr;
                int nc=c+dc;
                if(nr<0 || nr>=m||nc<0||nc>=n) continue;
                if(grid[nr][nc]!=INF) continue;
                grid[nr][nc]=grid[r][c]+1;
                q.push({nr,nc});
            }
        }
    }
};
