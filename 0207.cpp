class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        queue<int> Q;
        int numNodesTaken = 0;
        
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
            numNodesTaken++;
            
            for (auto v : graph[u])
            {
                if (--inDegree[v] == 0)
                    Q.push(v);
            }
        }
        
        return numCourses == numNodesTaken;
    }
};