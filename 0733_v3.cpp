class Solution
{
    #define WHITE 0
    #define BLACK 1
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        int m = image.size();
        int n = image[0].size();
        int initialColor = image[sr][sc];
        vector<vector<char>> color(m, vector<char>(n, WHITE));
        stack<pair<int, int>> S;
                
        image[sr][sc] = newColor;
        color[sr][sc] = BLACK;
        S.push({sr, sc});
        
        while (!S.empty())
        {
            auto [r, c] = S.top(); S.pop();
            vector<pair<int, int>> neighs = {{r, c-1}, {r, c+1}, {r-1, c}, {r+1, c}};
            
            for (auto [nr, nc] : neighs)
            {
                if (nr < 0 or nr == m or nc < 0 or nc == n) continue;
                if (color[nr][nc] == WHITE and image[nr][nc] == initialColor)
                {
                    image[nr][nc] = newColor;
                    color[nr][nc] = BLACK;
                    S.push({nr, nc});
                }
            }
        }
        
        return image;
    }
};