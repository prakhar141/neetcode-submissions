class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return "";
        unordered_map<char,char> mapST;
        unordered_map<char,char> mapTS;
        for(int i=0;i<s.length();i++){
            char a=s[i];
            char b=t[i];
            if(mapST.count(a)){
                if(mapST[a]!=b) return false;
            }
            else if(mapTS.count(b)){
                if(mapTS[b]!=a) return false;
            }
            else{
                mapST[a]=b;
                mapTS[b]=a;
            }
        }
        return true;
    }
};