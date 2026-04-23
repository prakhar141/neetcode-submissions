class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses);
        for(auto& pre:prerequisites){
            int course=pre[0];
            int prerequisite=pre[1];
            adj[prerequisite].push_back(course);
            inDegree[course]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        vector<int> result;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            result.push_back(curr);
            for(int neighbor:adj[curr]){
                inDegree[neighbor]--;
                if(inDegree[neighbor]==0){
                    q.push(neighbor);
                }
            }
        }
        if(result.size()==numCourses){
            return result;
        }
        else{
            return {};
        }
    }
};
