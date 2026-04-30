class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
      int count[2]={0,0};
      for(int student:students){
        count[student]++;
      }  
      for(int sandwhich:sandwiches){
        if(count[sandwhich]==0) break;
        count[sandwhich]--;
      }
      return count[0]+count[1];
    }
};