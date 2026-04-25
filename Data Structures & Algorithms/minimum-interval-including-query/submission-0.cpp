class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        int q=queries.size();
        vector<pair<int,int>> sortedQueries(q);
        for(int i=0;i<q;i++){
            sortedQueries[i]={queries[i],i};
            
        }
        sort(sortedQueries.begin(),sortedQueries.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> ans(q,-1);
        int i=0;
        for(auto&[query,originalIdx]:sortedQueries){
            while(i<intervals.size() && intervals[i][0]<=query){
                int len=intervals[i][1]-intervals[i][0]+1;
                int right=intervals[i][1];
                pq.push({len,right});
                i++;
            }
            while(!pq.empty()&&pq.top().second<query){
                pq.pop();
            }
            if(!pq.empty()){
                ans[originalIdx]=pq.top().first;
            }

        }
        return ans;

    }
};
