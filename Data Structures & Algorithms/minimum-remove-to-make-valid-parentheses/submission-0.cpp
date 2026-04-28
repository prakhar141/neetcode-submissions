class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> openIndices;
        unordered_set<int> toRemove;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') openIndices.push(i);
            else if(s[i]==')'){
                if(openIndices.empty()){
                    toRemove.insert(i);
                }
                else{
                    openIndices.pop();
                }
            }
        }
        while(!openIndices.empty()){
            toRemove.insert(openIndices.top());
            openIndices.pop();
        }
        string result;
        for(int i=0;i<s.size();i++){
            if(toRemove.find(i)==toRemove.end()) result +=s[i];
        }
        return result;

    }
};
