class Solution {
public:
vector<vector<bool>>visit;
    bool exist(vector<vector<char>>& board, string word) {
        string curr="";
        visit=vector<vector<bool>>(board.size(),vector<bool>(board[0].size(), false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(backtrack(board,word,curr,i,j,0))
                    return true;
            }
        }
        return false;
    }

    bool backtrack(vector<vector<char>>& board, string word, string curr, int i, int j, int ptr){
        if(ptr==word.size()) return true;
        int n=board.size(),m=board[0].size();
        if(i<0||i>=n||j<0||j>=m|| board[i][j]!=word[ptr]||visit[i][j]) return false;
        
        visit[i][j]=true;
        bool k= backtrack(board,word,curr,i,j+1,ptr+1)||
            backtrack(board,word,curr,i,j-1,ptr+1)||
            backtrack(board,word,curr,i+1,j,ptr+1)||
            backtrack(board,word,curr,i-1,j,ptr+1);
        visit[i][j]=false;
        return k;
    }
};
