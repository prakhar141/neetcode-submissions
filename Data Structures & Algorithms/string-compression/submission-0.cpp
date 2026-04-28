class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int write=0;
        int read=0;
        while(read<n){
            int groupStart=read;
            while(read<n && chars[read]==chars[groupStart]){
                read++;
            }
            chars[write++]=chars[groupStart];
            int groupLen=read-groupStart;
            if(groupLen>1){
                string countStr=to_string(groupLen);
                for(char digit:countStr){
                    chars[write++]=digit;
                }
            }
        }
        return write;
    }
};