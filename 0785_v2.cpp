class Solution
{
    #define WHITE 0
    #define BLACK 1
    #define SETA 0
    #define SETB 1
    
    bool dfs(int u, vector<vector<int>>& graph, vector<int>& color, vector<int>& set)
    {
        color[u] = BLACK;
        
        for (auto v : graph[u])
        {
            if (color[v] == BLACK)
            {
                if (set[u] == set[v]) return false;   
            }
            else
            {
                color[v] = BLACK;
                set[v] = set[u] == SETA ? SETB : SETA;
                if (dfs(v, graph, color, set) == false) return false;
            }
        }
        
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph)
    {           
        int n = graph.size();
        vector<int> color(n, WHITE);
        vector<int> set(n);
        
        for (int i = 0; i < n; i++)
        {
            if (color[i] == WHITE)
            {
                set[i] = SETA;
                if (dfs(i, graph, color, set) == false) return false;
            }
        }
        
        return true;
    }
};