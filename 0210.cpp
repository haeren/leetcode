class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        queue<int> Q;
        vector<int> result;
        
        for (auto prerequisite : prerequisites)
        {
            graph[prerequisite[1]].push_back(prerequisite[0]);
            inDegree[prerequisite[0]]++;
        }
        
        for (int i = 0; i < numCourses; i++)
            if (inDegree[i] == 0)
                Q.push(i);
        
        while(!Q.empty())
        {
            auto u = Q.front(); Q.pop();
            result.push_back(u);
            
            for (auto v : graph[u])
            {
                if (--inDegree[v] == 0)
                    Q.push(v);
            }
        }
        
        return numCourses == result.size() ? result : vector<int>{};
    }
};