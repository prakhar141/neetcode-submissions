class Solution {
public:
    bool backtrack(int idx,vector<int>& sticks,vector<int>& sides,int target){
        if(idx==sticks.size()){
            return sides[0]==target && sides[1]==target &&sides[2]==target && sides[3]==target;
        }
        for(int i=0;i<4;i++){
            if(sides[i]+sticks[idx]>target) continue;
            bool duplicate=false;
            for(int j=0;j<i;j++){
                if(sides[j]==sides[i]){
                    duplicate=true;
                    break;
                }
            }
            if(duplicate) continue;
            sides[i]+=sticks[idx];
            if(backtrack(idx+1,sticks,sides,target)) return true;
            sides[i]-=sticks[idx];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size()<4) return false;
        int sum=0;
        for(int x:matchsticks) sum+=x;
        if(sum%4 !=0) return false;
        int target=sum/4;
        sort(matchsticks.rbegin(),matchsticks.rend());
        if(matchsticks[0]>target) return false;
        vector<int> sides(4,0);
        return backtrack(0,matchsticks,sides,target);
        
    }
};