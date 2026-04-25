class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize !=0) return false;
        map<int,int> count;
        for(int card:hand){
            count[card]++;
        }
        while(!count.empty()){
            int start=count.begin()->first;
            for(int i=0;i<groupSize;i++){
                int needed=start+i;
                if(count.find(needed)==count.end()) return false;
                count[needed]--;
                if(count[needed]==0) count.erase(needed);
            }
        }
        return true;
    }
};
