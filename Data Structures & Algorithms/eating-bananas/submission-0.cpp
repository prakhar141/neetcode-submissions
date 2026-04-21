#include<algorithm>
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1;
        int hi=*max_element(piles.begin(),piles.end());
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(canFinish(piles,mid,h)){
                hi=mid;
            }
            else{
                lo=mid+1;
            }

        }
        return lo;
        
    }
    private:
    bool canFinish(vector<int>& piles, int k, int h){
        long long hoursneeded=0;
        for(int bananas:piles){
            hoursneeded+=(bananas+k-1)/k;
            if(hoursneeded>h){
                return false;
            }
            
        }
        return hoursneeded <= h;
    }
};
