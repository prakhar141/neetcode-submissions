class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> isPre(numCourses,vector<bool>(numCourses,false));
        for(auto& p:prerequisites){
            isPre[p[0]][p[1]]=true;
        }
        for(int k=0;k<numCourses;k++){
            for(int i=0;i<numCourses;i++){
                for(int j=0;j<numCourses;j++){
                    if(isPre[i][k] && isPre[k][j]){
                        isPre[i][j]=true;
                    }
                }
            }
        }
        vector<bool> answer;
        answer.reserve(queries.size());
        for(auto& q:queries){
            answer.push_back(isPre[q[0]][q[1]]);
        }
        return answer;
        
    }
};