class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> result;
        int max_height=-1;
        for(int i=heights.size()-1;i>=0;i--){
            if(heights[i]>max_height){
                result.push_back(i);
                max_height=heights[i];
            }

        }
        reverse(result.begin(),result.end());
        return result;
    }
};