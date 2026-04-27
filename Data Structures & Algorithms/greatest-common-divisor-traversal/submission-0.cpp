class DSU{
public:
    vector<int> parent,rank_;
    DSU(int n):parent(n),rank_(n,0){
        iota(parent.begin(),parent.end(),0);
    }
    int find(int x){
        if(parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }
    void unite(int x,int y){
        int rx=find(x);
        int ry=find(y);
        if(rx==ry) return;
        if(rank_[rx]<rank_[ry]) swap(rx,ry);
        parent[ry]=rx;
        if(rank_[rx]==rank_[ry]) rank_[rx]++;
    }
};
class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        for(int x:nums) if(x==1) return false;
        unordered_map<int,int> primeId;
        DSU dsu(n+100000);
        int nextId=n;
        for(int i=0;i<n;i++){
            int x=nums[i];
            for(int p=2;(long long)p * p<=x;p++){
                if(x%p==0){
                    if(!primeId.count(p)) primeId[p]=nextId++;
                    dsu.unite(i,primeId[p]);
                    while(x%p==0) x/=p;
                }
            }
            if(x>1){
                if(!primeId.count(x)) primeId[x]=nextId++;
                dsu.unite(i,primeId[x]);
            }
        }
        int root=dsu.find(0);
        for(int i=1;i<n;i++){
            if(dsu.find(i)!=root) return false;
        }
        return true;
        
    }
};