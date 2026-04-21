class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      heights.push_back(0);
      stack <int> st;
      int maxArea=0;
      for (int i=0;i<heights.size();i++){
        while(!st.empty() && heights[st.top()]>heights[i]){
            int currentHeight=heights[st.top()];
            st.pop();
            int leftblocker=st.empty() ? -1:st.top();
            int rightblocker=i;
            int width=rightblocker-leftblocker-1;
            maxArea=max(maxArea,width*currentHeight);
        }
        st.push(i);
      }
      return maxArea;

    }
};
