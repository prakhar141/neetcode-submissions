class Solution {
public:
    vector<string> pad={"","","abc","def","ghi","jkl","mno","pqrs"
    ,"tuv","wxyz"};
    vector<string> res;
    void backtrack(const string& digits,int i,string& curr){
        if(i==digits.size()){
            res.push_back(curr);
            return;
        }
        string& letters=pad[digits[i]-'0'];
        for(char c:letters){
            curr.push_back(c);
            backtrack(digits,i+1,curr);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string curr="";
        backtrack(digits,0,curr);
        return res;
        
    }
};
