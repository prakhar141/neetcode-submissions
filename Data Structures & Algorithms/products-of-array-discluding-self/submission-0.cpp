class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector <int> answer(n,1);
        int leftproduct=1;
        for(int i=0;i<n;i++){
            answer[i]=leftproduct;
            leftproduct=leftproduct*nums[i];
        }
        int rightproduct=1;
        for(int i=n-1;i>=0;i--){
            answer[i]=answer[i]*rightproduct;
            rightproduct=rightproduct*nums[i];
        }
        return answer;

    }
};
