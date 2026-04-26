class Solution {
public:
    string decodeString(string s) {
        stack<string> strStack;
        stack<int> numStack;
        string curStr="";
        int currNum=0;
        for(char c:s){
            if(isdigit(c)){
                currNum=currNum*10+(c-'0');
            }
            else if(c=='['){
                strStack.push(curStr);
                numStack.push(currNum);
                curStr="";
                currNum=0;
            }
            else if(c==']'){
                int k=numStack.top();
                numStack.pop();
                string prev=strStack.top();
                strStack.pop();
                string repeated="";
                for(int i=0;i<k;i++){
                    repeated+=curStr;
                }
                curStr=prev+repeated;
            }
            else{
                curStr+=c;
            }
        }
        return curStr;

    }
};