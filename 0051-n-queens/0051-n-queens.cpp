class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        char j = '.';
        string str(n, j);
        vector<string> ans(n, str);
        backtrack(n, ret, ans, 0);
        return ret;
    }
    void backtrack(int n, vector<vector<string>>& ret, vector<string>& board, int l){
        if(l >= n){
            ret.push_back(board);
            return;
        }

        for(int i = 0; i < n; i++){
            bool f = true;

            for(int j = 0; j < l; j++){
                if(board[j][i] == 'Q'){
                    f = false;
                    break;
                }
            }
            if(!f) continue;

            int m = l, k = i;

            while(--m >= 0 && --k >= 0){
                if(board[m][k] == 'Q'){
                    f = false;
                    break;
                }
            }
            if(!f) continue;

            m = l, k = i;

            while(--m >= 0 && ++k < n){
                if(board[m][k] == 'Q'){
                    f = false;
                    break;
                }
            }
            if(!f) continue;

            board[l][i] = 'Q';
            backtrack(n, ret, board, l + 1);
            board[l][i] = '.';
        }
    }
};