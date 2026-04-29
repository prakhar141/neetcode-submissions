class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int baseSatisfied=0;
        int windowSum=0;
        int maxSaved=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0) baseSatisfied+=customers[i];
            else if (i<minutes) windowSum+=customers[i];
        }
        maxSaved=windowSum;
        for(int i=minutes;i<n;i++){
            if(grumpy[i]==1) windowSum+=customers[i];
            if(grumpy[i-minutes]==1) windowSum -=customers[i-minutes];
            maxSaved=max(maxSaved,windowSum);
        }
        return baseSatisfied+maxSaved;
        
    }
};