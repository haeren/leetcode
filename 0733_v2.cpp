class Solution
{
    #define WHITE 0
    #define BLACK 1
    
    void dfs(int r, int c, int initialColor, int newColor, vector<vector<int>>& image, 
            vector<vector<char>>& color)
    {
        int m = image.size();
        int n = image[0].size();
        vector<pair<int, int>> neighs = {{r, c-1}, {r, c+1}, {r-1, c}, {r+1, c}};
        
        image[r][c] = newColor;
        color[r][c] = BLACK;
        
        for (auto [nr, nc] : neighs)
        {
            if (nr < 0 or nr == m or nc < 0 or nc == n) continue;
            if (color[nr][nc] == WHITE and image[nr][nc] == initialColor)
                dfs(nr, nc, initialColor, newColor, image, color);
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        int m = image.size();
        int n = image[0].size();
        vector<vector<char>> color(m, vector<char>(n, WHITE));
        
        dfs(sr, sc, image[sr][sc], newColor, image, color);
        return image;
    }
};