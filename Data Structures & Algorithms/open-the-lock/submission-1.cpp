class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(),deadends.end());
        if(visited.count("0000")) return -1;
        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        int steps=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                string cur=q.front();
                q.pop();
                if(cur==target){
                    return steps;
                }
                for(int j=0;j<4;j++){
                    char original=cur[j];
                    cur[j]=(original=='9') ? '0':original+1;
                    if(!visited.count(cur)){
                        visited.insert(cur);
                        q.push(cur);
                    }
                    cur[j]=(original=='0') ? '9':original-1;
                    if(!visited.count(cur)){
                        visited.insert(cur);
                        q.push(cur);
                    }
                    cur[j]=original;
                }
            }
            steps++;
        }
        return -1;

    }
};