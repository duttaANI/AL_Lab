#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

   
    
    bool searchWord(vector< vector<char> >& board, int i,int j, int idx, string word, vector< vector<bool> >& visited)
    {
        
        if(idx == word.length()) return true;
        
        if(i<0 || i>=board.size() || j<0 || j>=board[i].size() || board[i][j]!=word[idx] || visited[i][j]) return false;
        
        
        visited[i][j] = true;
        
        
        if(
            searchWord(board , i+1 , j , idx+1 , word, visited) ||
            searchWord(board , i-1 , j , idx+1 , word, visited) ||
            searchWord(board , i , j-1 , idx+1 , word, visited) ||
            searchWord(board , i , j+1 , idx+1 , word, visited) ||  // extra corners now onwards
            searchWord(board , i-1 , j-1 , idx+1 , word, visited) ||  // top left
            searchWord(board , i-1 , j+1 , idx+1 , word, visited) ||  // top right
            searchWord(board , i+1 , j-1 , idx+1 , word, visited) ||  // bottom left
            searchWord(board , i+1 , j+1 , idx+1 , word, visited)   // bottom right
        )
        {
            return true;     
        }
        
        visited[i][j]= false;
        
        return false;
    }

 bool exist(vector< vector<char> >& board, string word) {
        
        int rows = board.size();
        int cols = board[0].size();
        vector< vector<bool> > visited(rows, vector<bool>(cols,false));

        
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

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T,i,H,W,x,y;
    cin >> T;
    string s = "ACMMANIPAL";
    for(i=0;i<T;++i){
        cin >> H >> W; // height , width
        vector< vector<char> > mat ( H , vector<char> (W,'0')  );
        
        for(x=0; x<H; ++x){
            for(y=0; y<W; ++y){
                cin >> mat[x][y];
            }
        }
        
        if(exist(mat,s))
            cout << "YES\n";
        else
            cout << "NO\n";
        
        mat.clear();
    }
    return 0;
}
