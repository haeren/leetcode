class Solution
{
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        #define WHITE 0
        #define BLACK 1 
        int n = isConnected.size();
        vector<char> color(n, WHITE);
        int counter = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (color[i] == BLACK) continue;
            
            counter++;
            color[i] = BLACK;
            
            queue<int> myQ;
            myQ.push(i);
            
            while (!myQ.empty())
            {
                int u = myQ.front(); myQ.pop();
                
                for (int v = 0; v < isConnected[i].size(); v++)
                {
                    if (isConnected[u][v] and color[v] == WHITE)
                    {
                        color[v] = BLACK;
                        myQ.push(v);
                    }
                }
            }     
        }
        
        return counter;
    }
};