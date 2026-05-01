class Solution {
public:
    vector<int> prefix;
    int total=0;
    Solution(vector<int>& w) {
        for(int weight:w){
            total+=weight;
            prefix.push_back(total);
        }
        
    }
    
    int pickIndex() {
        int r=rand()% total+1;
        auto it=lower_bound(prefix.begin(),prefix.end(),r);
        return it-prefix.begin();
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */