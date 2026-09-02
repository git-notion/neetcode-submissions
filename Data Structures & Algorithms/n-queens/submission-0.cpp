class Solution {
public:
    vector<vector<string>>ans;
    unordered_set<int>col;
    unordered_set<int>posdiag;
    unordered_set<int>negdiag;
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        backtrack(0,n,board);
        return ans;
    }
    void backtrack(int r, int n, vector<string>board)
    {
        if(r==board.size()){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(col.count(i)||posdiag.count(r+i)||negdiag.count(r-i))
            {
                continue;
            }
            col.insert(i);
            posdiag.insert(r+i);
            negdiag.insert(r-i);
            board[r][i]= 'Q';

            backtrack(r+1,n,board);

            col.erase(i);
            posdiag.erase(r+i);
            negdiag.erase(r-i);
            board[r][i]= '.';
        }
    }
};