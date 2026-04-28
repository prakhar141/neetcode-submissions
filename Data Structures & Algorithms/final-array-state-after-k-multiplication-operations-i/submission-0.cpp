class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push({(long long)nums[i],i});
        }
        while(k--){
            auto[val,idx]=pq.top();
            pq.pop();
            val*=multiplier;
            pq.push({val,idx});
        }
        while(!pq.empty()){
            auto[val,idx]=pq.top();
            pq.pop();
            nums[idx]=(int)val;
        }
        
        return nums;
    }
};