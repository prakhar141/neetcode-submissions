class DSU{
public:
    vector<int> parent,rank_;
    int components;
    DSU(int n):parent(n),rank_(n,0),components(n){
        iota(parent.begin(),parent.end(),0);

    }
    int find(int x){
        if(parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }
    bool unite(int x,int y){
        int px=find(x),py=find(y);
        if(px==py) return false;
        if(rank_[px]<rank_[py]) swap(px,py);
        parent[py]=px;
        if(rank_[px]==rank_[py]) rank_[px]++;
        components--;
        return true;
    }
};
class Solution {
public:
    int kruskal(int n,vector<vector<int>>& edges,int skip,int pre){
        DSU dsu(n);
        int weight=0;
        if(pre!=-1){
            weight+=edges[pre][2];
            dsu.unite(edges[pre][0],edges[pre][1]);
        }
        for(int i=0;i<edges.size();i++){
            if(i==skip ||i==pre) continue;
            auto& e=edges[i];
            if(dsu.unite(e[0],e[1])) weight+=e[2];
        }
        return dsu.components==1 ? weight:INT_MAX;

    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        for(int i=0;i<m;i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(),edges.end(),[](auto& a,auto& b){return a[2]<b[2];});
        int baseMST=kruskal(n,edges,-1,-1);
        vector<int> critical,psuedo;
        for(int i=0;i<m;i++){
            if(kruskal(n,edges,i,-1)>baseMST){
                critical.push_back(edges[i][3]);
            }
            else if(kruskal(n,edges,-1,i)==baseMST){
                psuedo.push_back(edges[i][3]);
            }
        }
        return {critical,psuedo};


        
    }
};