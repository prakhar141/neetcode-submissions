class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26,0);
        for(char c:s) freq[c-'a']++;
        int n=s.size();
        for(int f:freq){
            if(f>(n+1)/2) return "";
        }
        priority_queue<pair<int,char>> pq;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                pq.push({freq[i],'a'+i});
            }
        }
        string result="";
        pair<int,char> prev={0,'#'};
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            result+=curr.second;
            curr.first--;
            if(prev.first>0) pq.push(prev);
            prev=curr;
        }
        return result;
    }
};