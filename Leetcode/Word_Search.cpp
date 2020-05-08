class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols,false));

        
        for(int i=0; i<rows; ++i )
        {
            for(int j=0; j<cols;++j)
            {
                if(board[i][j] == word[0] && searchWord(board, i, j, 0, word, visited ))
                {
                        return true;
                }
            }
            
        }
        
        return false;
    }
    
    bool searchWord(vector<vector<char>>& board, int i,int j, int idx, string word, vector<vector<bool>>& visited)
    {
        
        if(idx == word.length()) return true;
        
        if(i<0 || i>=board.size() || j<0 || j>=board[i].size() || board[i][j]!=word[idx] || visited[i][j]) return false;
        
        
        visited[i][j] = true;
        
        
        if(
            searchWord(board , i+1 , j , idx+1 , word, visited) ||
            searchWord(board , i-1 , j , idx+1 , word, visited) ||
            searchWord(board , i , j-1 , idx+1 , word, visited) ||
            searchWord(board , i , j+1 , idx+1 , word, visited)
        )
        {
            return true;     
        }
        
        visited[i][j]= false;
        
        return false;
    }
};
