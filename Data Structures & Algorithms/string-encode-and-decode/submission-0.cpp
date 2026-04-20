class Solution {
public:

    string encode(vector<string>& strs) {
        string result="";
        for (int i=0;i<strs.size();i++){
            int len=strs[i].size();
            result+=to_string(len)+"#"+strs[i];
        }
        return result;

    }

    vector<string> decode(string s) {
        vector <string> result;
        int i=0;
        while(i<s.size()){
            string lenStr="";
            while(s[i]!='#'){
                lenStr+=s[i];
                i++;
            }
            i++;
            int len=stoi(lenStr);
            string word="";
            for(int j=0;j<len;j++){
                word+=s[i];
                i++;
            }
            result.push_back(word);

        }
        return result;

    }
};
