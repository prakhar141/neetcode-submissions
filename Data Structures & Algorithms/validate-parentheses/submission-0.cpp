class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        //go through each character one by one
        for (int i = 0; i < s.length(); i++){
            char ch=s[i];
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
                continue;
            }
            else{
                if (st.empty())
                return false;
            }
            char top=st.top();
            if(top=='(' && ch==')'){
                st.pop();
            }
            else if (top=='{' && ch=='}'){
                st.pop();
            }
            else if(top=='[' && ch==']'){
                st.pop();
            }
            else{
                return false;
            }
        }
        return st.empty();

    }
};
