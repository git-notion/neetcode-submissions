class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        for(int i=0;i<9;i++){
            unordered_map<char,int> c,d;
            for(int j=0;j<9;j++){
                c[board[i][j]]++;
                d[board[j][i]]++;
                if((board[i][j]!='.'&&c[board[i][j]]>1)||(d[board[j][i]]>1&&board[j][i]!='.')){
                    cout<<board[i][j]<<" "<<d[board[j][i]]<<" i: "<<i<<" j "<<j;
                    return false;
                }
            }
        }
        
        for(int row=0;row<3;row++){
            
            for(int col=0;col<3;col++){
                unordered_map<char,int> a;
                int r=3;
                int j=0;
                while(r--){
                    a[board[row*3+j][col*3]]++;
                    cout<<board[row*3+j][col*3]<<" ";
                    j++;
                }
                j=0;r=3;
                while(r--){
                    a[board[row*3+j][col*3+1]]++;
                    cout<<board[row*3+j][col*3+1]<<" ";
                    j++;
                }
                j=0;r=3;

                while(r--){
                    a[board[row*3+j][col*3+2]]++;
                    cout<<board[row*3+j][col*3+2]<<" ";
                    j++;
                }
                for(auto i:a){
                //cout<<i.first<<" "<<i.second<<endl;
                if(i.second>1&&i.first!='.'){
                    cout<<i.first<<" "<<i.second;
                    return false;
                }
                }cout<<endl;
            }
        }
        return true;
    }

};
