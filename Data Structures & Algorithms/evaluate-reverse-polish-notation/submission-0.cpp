#include<string>
#include<vector>
#include<stack>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        for (const string& token:tokens){
            if(token=="+" || token =="-" ||token =="*"|| token=="/"){
                int right=st.top();
                st.pop();
                int left=st.top();
                st.pop();
                int result;
                if(token=="+"){
                    result=right+left;
                }
                else if (token=="-"){
                    result=left-right;
                }
                else if (token=="*"){
                    result=right*left;
                }
                else{
                    result=left/right;
                }
                st.push(result);
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
        
    }
};
