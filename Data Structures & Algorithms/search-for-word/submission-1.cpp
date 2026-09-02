class Solution {
public:
    int ROWS, COLS;
    vector<vector<bool>> visited;

    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();
        visited = vector<vector<bool>>(ROWS, vector<bool>(COLS, false));
        for(int i=0;i< ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(dfs(board,word,i,j,0)){
                   return true; 
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word,int r,int c,int i){
        if(i==word.length()){
            return true;
        }
        if(r>=ROWS || c>=COLS || r < 0 || c < 0||
            board[r][c] != word[i] || visited[r][c]){
            return false;
        }
        visited[r][c] = true;
        bool res =  dfs(board,word,r-1,c,i+1)||
                    dfs(board,word,r,c-1,i+1)||
                    dfs(board,word,r+1,c,i+1)||
                    dfs(board,word,r,c+1,i+1);
        visited[r][c] = false;
        return res;
    }
};
