class Solution {
public:
    double dfs(const string& src,const string& dst,unordered_map<string,unordered_map<string,double>>& graph,unordered_set<string>& visited){
        if(graph.find(src)==graph.end()) return -1.0;
        if(src==dst) return 1.0;
        visited.insert(src);
        for(auto&[neighbor,weight]:graph[src]){
            if(visited.count(neighbor)) continue;
            double subresult=dfs(neighbor,dst,graph,visited);
            if(subresult!=-1.0){
                return weight*subresult;
            }
        }
        return -1.0;


    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> graph;
        vector<double> results;
        for(int i=0;i<equations.size();i++){
            string a =equations[i][0],b=equations[i][1];
            double v=values[i];
            graph[a][b]=v;
            graph[b][a]=1.0/v;
            
        }
        for(auto& q:queries){
            unordered_set<string> visited;
            results.push_back(dfs(q[0],q[1],graph,visited));
            }
        return results;          
        
        
    }
};