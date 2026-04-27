class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
        
    }
    void unite(int x ,int y){
        int rx=find(x),ry=find(y);
        if(rx!=ry) parent[rx]=ry;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        unordered_map<string,int> emailToAcc;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string& email=accounts[i][j];
                if(emailToAcc.count(email)){
                    unite(i,emailToAcc[email]);
                }
                else{
                    emailToAcc[email]=i;
                }
            }
        }
        unordered_map<int,set<string>> rootToEmails;
        for(auto& [email,accIdx]:emailToAcc){
            int root=find(accIdx);
            rootToEmails[root].insert(email);
        }
        vector<vector<string>> result;
        for(auto& [root,emails]:rootToEmails){
            vector<string> merged;
            merged.push_back(accounts[root][0]);
            merged.insert(merged.end(),emails.begin(),emails.end());
            result.push_back(merged);
        }
        return result;
       
    }
};