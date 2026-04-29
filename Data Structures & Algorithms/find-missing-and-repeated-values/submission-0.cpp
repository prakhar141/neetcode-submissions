class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int total =n*n;
        vector<int> count(total+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                count[grid[i][j]]++;
            }
        }
        vector<int> ans(2,0);
        for(int v=1;v<=total;v++){
            if(count[v]==2 ) ans[0]=v;
            else if(count[v]==0) ans[1]=v;
        }
        return ans;
    }
};