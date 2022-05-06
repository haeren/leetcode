class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        int n = grid.size();
        if (grid[0][0] != 0) return -1;
        if (grid[n-1][n-1] != 0) return -1;
        if (n == 1) return 1;
        
        queue<tuple<int, int, int>> myQ;
        myQ.push({0, 0, 1});
        grid[0][0] = 1;
        
        while (!myQ.empty())
        {
            auto [row, col, len] = myQ.front(); myQ.pop();
            
            vector<pair<int, int>> neighs = {
                {row-1, col-1}, {row-1, col}, {row-1, col+1},
                {row, col-1} ,                {row, col+1}  ,
                {row+1, col-1}, {row+1, col}, {row+1, col+1}
            };
            
            for (auto [n_row, n_col] : neighs)
            {
                if (n_row == n-1 and n_col == n-1)
                    return len + 1;
                if (n_row < 0 or n_row >= n or n_col < 0 or n_col >= n)
                    continue;
                if (grid[n_row][n_col] == 0)
                {
                    grid[n_row][n_col] = 1;
                    myQ.push({n_row, n_col, len+1});
                }
            }
        }
        
        return -1;
    }
};