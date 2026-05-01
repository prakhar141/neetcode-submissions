class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmails;
        for(string& email:emails){
            string cleanEmail;
            int atPos=email.find('@');
            string local=email.substr(0,atPos);
            string domain=email.substr(atPos);
            for(char c:local){
                if(c=='+') break;
                if(c=='.') continue;
                cleanEmail+=c;
            }
            cleanEmail+=domain;
            uniqueEmails.insert(cleanEmail);
        }
        return uniqueEmails.size();

    }
};