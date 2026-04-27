class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<unordered_set<int>> adj(n);
        vector<int> degree(n,0);
        for(auto& e:edges){
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue<int> leaves;
        for(int i=0;i<n;i++){
            if(degree[i]==1) leaves.push(i);
        }
        int remaining=n;
        while(remaining>2){
            int sz=leaves.size();
            remaining-=sz;
            for(int i=0;i<sz;i++){
                int leaf=leaves.front();
                leaves.pop();
                for(int nb:adj[leaf]){
                    degree[nb]--;
                    if(degree[nb]==1) leaves.push(nb);
                }
            }
        }
        vector<int> result;
        while(!leaves.empty()){
            result.push_back(leaves.front());
            leaves.pop();
        }
        return result;

    }
};