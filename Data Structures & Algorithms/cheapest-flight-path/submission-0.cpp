class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF=1e7;
        vector<int> dist(n,INF);
        dist[src]=0;
        for(int i=0;i<=k;i++){
            vector<int> next=dist;
            for(auto& f:flights){
                int u=f[0];
                int v=f[1];
                int price=f[2];
                if (dist[u]==INF) continue;
                if(dist[u]+price<next[v]) next[v]=dist[u]+price;
            }
            dist=next;
        }
        return dist[dst]==INF ?-1:dist[dst];
    }
};
