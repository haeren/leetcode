class Solution
{
public:
    #define WHITE 0
    #define BLACK 1
    
    void dfs(int u, vector<vector<int>>& isConnected, vector<char>& color)
    {
        color[u] = BLACK;
        for (int v = 0; v < isConnected[u].size(); v++)
            if (isConnected[u][v] && color[v] == WHITE)
                dfs(v, isConnected, color);
    }
    
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();
        vector<char> color(n, WHITE);
        int counter = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (color[i] == WHITE)
            {
                counter++;
                dfs(i, isConnected, color);
            }
        }
        
        return counter;
    }
};