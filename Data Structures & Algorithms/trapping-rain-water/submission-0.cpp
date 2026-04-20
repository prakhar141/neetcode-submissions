class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int leftmax=height[left];
        int rightmax=height[right];
        int water=0;
        while(left<right){
            if (leftmax<rightmax){
                left++;
                if (leftmax<height[left]){
                    leftmax=height[left];
                }
                else{
                    water+=leftmax-height[left];
                }
            }
            else{
                right--;
                if(rightmax<height[right]){
                    rightmax=height[right];
                }
                else{
                    water+=rightmax-height[right];
                }
            }
        }
        return water;
    }
};
