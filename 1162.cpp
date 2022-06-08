class Solution
{
public:
    int maxDistance(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int maxDist = 0;
        queue<tuple<int, int, int>> Q;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    Q.push({i, j, 0});

        if (Q.empty() or Q.size() == n*n) return -1;
        
        while (!Q.empty())
        {
            auto [r, c, d] = Q.front(); Q.pop();
            vector<pair<int, int>> neighs = {{r-1, c}, {r+1, c}, {r, c-1}, {r, c+1}};
            
            for (auto [nr, nc] : neighs)
            {
                if (nr < 0 or nc < 0 or nr == n or nc == n) continue;
                if (grid[nr][nc] == 0)
                {
                    grid[nr][nc] = 1;
                    Q.push({nr, nc, d+1});
                    if (d+1 > maxDist) maxDist = d+1;
                }
            }
        }
        
        return maxDist;
    }
};