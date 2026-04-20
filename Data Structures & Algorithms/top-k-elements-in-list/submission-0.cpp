class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int,int> freq;
      for (int i=0;i<nums.size();i++){
        freq[nums[i]]++;
      }  
      vector<vector<int>> bucket(nums.size()+1);
      for (auto& pair:freq){
        int number=pair.first;
        int count=pair.second;
        bucket[count].push_back(number);

      }
      vector<int> result;
      for(int i=nums.size();i>=1 && result.size()<k;i--){
        for (int j=0;j<bucket[i].size() && result.size()<k;j++){
            result.push_back(bucket[i][j]);
        }
      }
      return result;
    }

};
