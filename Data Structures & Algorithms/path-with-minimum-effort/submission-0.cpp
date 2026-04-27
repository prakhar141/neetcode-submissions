class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows=heights.size(),cols=heights[0].size();
        vector<vector<int>> effort(rows,vector<int>(cols,INT_MAX));
        effort[0][0]=0;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;
        pq.push({0,0,0});
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        while(!pq.empty()){
            auto[e,r,c]=pq.top();
            pq.pop();
            if(r==rows-1 && c==cols-1){
                return e;
            }
            if(e>effort[r][c]) continue;
            for(int d=0;d<4;d++){
                int nr=r+dr[d],nc=c+dc[d];
                if(nr<0||nr>=rows||nc<0||nc>=cols) continue;
                int newEffort=max(e,abs(heights[nr][nc]-heights[r][c]));
                if(newEffort<effort[nr][nc]){
                    effort[nr][nc]=newEffort;
                    pq.push({newEffort,nr,nc});
                }
            }
        }
        return 0;
    }
};