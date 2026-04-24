class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto& t:times){
            int u=t[0],v=t[1],w=t[2];
            graph[u].push_back({v,w});
        }
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        using P=pair<int,int>;
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto[d,u]=pq.top();
            pq.pop();
            if(d>dist[u]) continue;
            for(auto& [v,w]:graph[u]){
                if(dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                    pq.push({dist[v],v});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};
