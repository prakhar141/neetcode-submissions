class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,unordered_set<char>> adj;
        unordered_map<char,int> indegree;
        for(const string& w:words){
            for(char c:w){
                indegree[c]=0;
            }
        }
        for(int i=0;i+1<words.size();i++){
            const string&w1=words[i];
            const string& w2=words[i+1];
            int len=min(w1.size(),w2.size());
            bool foundDiff=false;
            for(int j=0;j<len;++j){
                if(w1[j]!=w2[j]){
                    if(!adj[w1[j]].count(w2[j])){
                        adj[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    foundDiff=true;
                    break;

                }
            }
            if(!foundDiff && w1.size()>w2.size()){
                return "";
            }
        }
        queue<char> q;
        for(const auto& p:indegree){
            if(p.second==0) q.push(p.first);

        }
        string result;
        while(!q.empty()){
            char u=q.front();
            q.pop();
            result+=u;
            for(char v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0)q.push(v);
            }
        }
        if(result.size()!=indegree.size()){
            return "";
        }
        return result;
    }
};
