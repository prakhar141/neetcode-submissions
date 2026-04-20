class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0;
        int right=heights.size()-1;
        int maxwater=0;
        while(left<right){
            int width=right-left;
            int height=min(heights[left],heights[right]);
            int water=height*width;
            maxwater=max(maxwater,water);
            if(heights[left]<heights[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxwater;
    }
};
