class DisjointSet
{
    vector<int> sets;
    
public:
    DisjointSet(int n)
    {
        sets.resize(n, -1);
    }
    
    int find(int u)
    {
        if (sets[u] < 0) return u;
        int root = find(sets[u]);
        sets[u] = root; // Path compression
        return root;
    }
    
    void join(int u, int v)
    {
        if (u == v) return;
        if (sets[u] >= 0) u = find(u);
        if (sets[v] >= 0) v = find(v);
        
        // Union-by-Size
        if (sets[u] < sets[v])
        {
            sets[u] += sets[v];
            sets[v] = u;
        }
        else
        {
            sets[v] += sets[u];
            sets[u] = v;
        }
    }
    
    int size(int u)
    {
        return -sets[u];
    }
};

class Solution
{
public:
    bool containsCycle(vector<vector<char>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        DisjointSet ds(m*n);
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                vector<pair<int, int>> neighs = {{i, j-1}, {i-1, j}};   // Left and up
                for (auto [nr, nc] : neighs)
                {
                    if (nr >= 0 and nc >= 0 and grid[nr][nc] == grid[i][j])
                    {
                        // Row major order
                        int u = i*n + j;
                        int v = nr*n + nc;
                        
                        int set1 = ds.find(u);
                        int set2 = ds.find(v);
                        
                        if (set1 == set2)
                        {
                            if (ds.size(set1) >= 4) return true;
                        }
                        else
                        {
                            ds.join(set1, set2);
                        }
                    }
                }
            }
        }
        
        return false;
    }
};