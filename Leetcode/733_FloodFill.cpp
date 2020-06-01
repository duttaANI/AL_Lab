class Solution {
public:
    
    int dx[4] = {1,0,-1,0}; int dy[4] = {0,1,0,-1}; 
    
    void paint (vector<vector<int>>& image, int newColor, int oldColor, int sr, int sc, vector<vector<bool>>& visited) {
        image[sr][sc] = newColor;
        visited[sr][sc] =true;
        int x,y;
        for (int i=0; i<4; ++i) {
            x = sr + dx[i]; y = sc + dy[i];
            
            if( x>=0 && x<image.size() && y>=0 && y<image[0].size() && image[x][y]==oldColor && !visited[x][y])
            {   
                paint(image, newColor, oldColor, x, y, visited);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        image[sr][sc] = newColor;
        
        int x,y;
        vector<vector<bool>> visited (image.size(), vector<bool> (image[0].size(), false));
        visited[sr][sc] = true;
        for (int i=0; i<4; ++i) {
            x = sr + dx[i]; y = sc + dy[i];
            
            if( x>=0 && x<image.size() && y>=0 && y<image[0].size() && image[x][y]==oldColor)
            {
                paint(image, newColor, oldColor, x, y , visited);
            }
            
        }
        return image;
    }
};