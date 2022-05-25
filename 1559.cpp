class Solution
{
    #define WHITE 0
    #define BLACK 1
    
    bool dfs(int r, int c, vector<vector<char>>& grid, vector<vector<char>>& color, vector<vector<int>>& dist)
    {
        int m = grid.size();
        int n = grid[0].size();
        color[r][c] = BLACK;
        vector<pair<int, int>> neighs = {{r-1, c}, {r+1, c}, {r, c-1}, {r, c+1}};
        
        for (auto [nr, nc] : neighs)
        {
            if (nr < 0 or nr == m or nc < 0 or nc == n) continue;
            if (grid[nr][nc] != grid[r][c]) continue;
            if (color[nr][nc] == BLACK)
            {
                if (dist[nr][nc] - dist[r][c] >= 3) return true;
                continue;
            }
            
            dist[nr][nc] = dist[r][c] + 1;
            if (dfs(nr, nc, grid, color, dist)) return true;
        }
        
        return false;
    }
    
public:
    bool containsCycle(vector<vector<char>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<char>> color(m, vector<char>(n, WHITE));
        vector<vector<int>> dist(m, vector<int>(n, 1));
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (color[i][j] == BLACK) continue;
                if (dfs(i, j, grid, color, dist)) return true;
            }
        }
        
        return false;
    }
};