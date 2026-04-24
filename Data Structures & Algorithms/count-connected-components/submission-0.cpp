class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& e :edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector <bool> visited(n,false);
        int count=0;for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                visited[i]=true;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int curr=q.front();
                    q.pop();
                    for(int neighbor:adj[curr]){
                        if(!visited[neighbor]){
                            visited[neighbor]=true;
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        return count;

    }
};
