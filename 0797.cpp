class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        int destination = graph.size() - 1;
        vector<vector<int>> result;
        queue<vector<int>> Q;
        Q.push({0});
        
        while (!Q.empty())
        {
            auto path = Q.front(); Q.pop();
            int currentNode = path.back();
            
            if (currentNode == destination)
            {
                result.push_back(path);
            }
            else
            {
                vector<int> nextNodes = graph[currentNode];

                for (int node : nextNodes)
                {
                    vector<int> nextPath = path;
                    nextPath.push_back(node);
                    Q.push(nextPath);
                }
            }
        }
        
        return result;
    }
};