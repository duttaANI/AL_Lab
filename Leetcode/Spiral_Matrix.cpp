class Solution {
public:
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans ;
        if(matrix.size()==0)
            return ans;
        int R = matrix.size();  int C = matrix[0].size();
        
        vector<vector<int>> seen ( R , vector<int> (C));
        
        int dr[4] = {0, 1,  0, -1}; // dir row
        int dc[4] = {1, 0, -1,  0}; // dir col
        int r=0,c=0,di=0;
        for(int i=0; i < R*C;++i)
        {
            ans.push_back(matrix[r][c]);
            seen[r][c] = true;
            int cr = r + dr[di];   // current row
            int cc = c + dc[di];   // current col
            
            if(0 <= cr && cr<R && 0<=cc && cc<C && !seen[cr][cc])
            {
                r = cr;
                c = cc;
            }
            else
            {
                di = (di + 1)%4;
                r = r + dr[di];
                c = c + dc[di];
            }
        }
        
        return ans;
    }
};