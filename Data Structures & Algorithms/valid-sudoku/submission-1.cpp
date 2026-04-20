class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0;i<9;i++){
            int seen[10]={0};
            for (int j=0;j<9;j++){
                char c = board[i][j];
                if(c!='.'){
                    int num= c-'0';
                    if(seen[num]==1){
                        return false;
                    }
                    seen[num]=1;
                }
            }
        }
        for (int i=0;i<9;i++){
            int seen[10]={0};
            for (int j=0;j<9;j++){
                char c = board[j][i];
                if(c !='.'){
                    int num = c-'0';
                    if(seen[num]==1){
                        return false;
                    }
                    seen[num]=1;

                }
            }
        }
        for (int boxrow=0;boxrow<9;boxrow+=3){
            for (int colrow=0;colrow<9;colrow+=3){
                int seen[10]={0};
                for (int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        char c=board[boxrow+i][colrow+j];
                        if(c != '.'){
                            int num= c-'0';
                            if (seen[num]==1){
                                return false;
                            }
                            seen[num]=1;
                        }
                    }
                }
            }
        }
        return true;
    }
};
