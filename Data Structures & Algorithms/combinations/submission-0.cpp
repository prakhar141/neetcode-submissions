class Solution {
    vector<vector<int>> result;
    vector<int> current;
public:
    void backtrack(int start,int n,int k) {
        
        if(current.size()==k){
            result.push_back(current);
            return;
        }
        int need=k-current.size();
        for(int i=start;i<=n-need+1;i++){
            current.push_back(i);
            backtrack(i+1,n,k);
            current.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n,int k){
        result.clear();
        current.clear();
        backtrack(1,n,k);
        return result;
    }
};