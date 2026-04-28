class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<long long> count(n,0);
        priority_queue<int,vector<int>,greater<>> avaliable;
        for(int i=0;i<n;i++){
            avaliable.push(i);
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> busy;
        for(auto& m:meetings){
            long long start=m[0];
            long long end=m[1];
        
           while(!busy.empty() && busy.top().first<=start){
                avaliable.push(busy.top().second);
                busy.pop();
            }
        
            if(!avaliable.empty()){
                int room=avaliable.top();
                avaliable.pop();
                busy.push({end,room});
                count[room]++;
            }
            else{
                auto[freeTime,room]=busy.top();
                busy.pop();
                long long newEnd=freeTime+(end-start);
                busy.push({newEnd,room});
                count[room]++;
            }
        }
        
        int best=0;
        for(int i=1;i<n;i++){
            if(count[i]>count[best]) best=i;
        }
        return best;

    }
};