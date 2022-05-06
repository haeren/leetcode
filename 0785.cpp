class Solution
{
public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        #define WHITE 0
        #define BLACK 1
        #define SETA 0
        #define SETB 1
            
        int n = graph.size();
        vector<int> color(n, WHITE);
        vector<int> set(n);
        queue<int> myQ;
        
        for (int i = 0; i < n; i++)
        {
            if (color[i] == WHITE)
            {
                color[i] = BLACK;
                set[i] = SETA;
                myQ.push(i);
                
                while(!myQ.empty())
                {
                    int u = myQ.front(); myQ.pop();
                    
                    for (int j = 0; j < graph[u].size(); j++)
                    {
                        int v = graph[u][j];
                        
                        if (color[v] == BLACK)
                        {
                            if (set[u] == set[v])
                                return false;
                        }
                        else
                        {
                            color[v] = BLACK;
                            set[v] = set[u] == SETA ? SETB : SETA;
                            myQ.push(v);
                        }
                    }
                }
            }
        }
        
        return true;
    }
};