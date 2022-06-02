class Solution
{
    #define WHITE 0
    #define GRAY  1
    #define BLACK 2
    
    bool dfs(int u, vector<vector<int>>& graph, vector<int>& color)
    {
        color[u] = GRAY;
        
        for (auto v : graph[u])
        {
            if (color[v] == GRAY)   // Back edge
                return false;
            if (color[v] == WHITE)
                if (dfs(v, graph, color) == false)
                    return false;
        }
        
        color[u] = BLACK;
        
        return true;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> color(numCourses, WHITE);
        
        for (auto prerequisite : prerequisites)
            graph[prerequisite[1]].push_back(prerequisite[0]);
       
        for (int i = 0; i < numCourses; i++)
            if (color[i] == WHITE)
                if (dfs(i, graph, color) == false)
                    return false; 

        return true;
    }
};