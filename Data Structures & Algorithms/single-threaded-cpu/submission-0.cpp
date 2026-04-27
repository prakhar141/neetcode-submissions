class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int  n=tasks.size();
        vector<tuple<int,int,int>> indexed;
        for(int i=0;i<n;i++){
            indexed.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(indexed.begin(),indexed.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        vector<int> result;
        long long currentTime=0;
        int i=0;
        while(i<n||!pq.empty()){
            while(i<n && get<0>(indexed[i])<=currentTime){
                pq.push({get<1>(indexed[i]),get<2>(indexed[i])});
                i++;
            }
            if(pq.empty()){
                currentTime=get<0>(indexed[i]);
            }
            else{
                auto[procTime,idx]=pq.top();
                pq.pop();
                currentTime+=procTime;
                result.push_back(idx);
            }
        }
        return result;

    }
};