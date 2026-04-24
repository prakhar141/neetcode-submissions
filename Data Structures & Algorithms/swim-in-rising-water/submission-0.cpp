class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=grid[0][0];
        using T=tuple<int,int,int>;
        priority_queue<T,vector<T>,greater<T>> pq;
        pq.emplace(dist[0][0],0,0);
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!pq.empty()){
            auto[cost,r,c]=pq.top();
            pq.pop();
            if(r==n-1 &&c==n-1) return cost;
            if(cost>dist[r][c]) continue;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr<0 || nr>=n|| nc<0|| nc>=n) continue;
                int newcost=max(cost,grid[nr][nc]);
                if(newcost<dist[nr][nc]){
                    dist[nr][nc]=newcost;
                    pq.emplace(newcost,nr,nc);
                }
            }
        }
        return dist[n-1][n-1];
    }
};
