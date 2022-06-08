class Solution
{
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time)
    {
        vector<vector<int>> G(n);
        vector<int> inDegree(n, 0);
        vector<int> T(n, 0);
        
        for (int i = 0; i < relations.size(); i++)
        {
            G[relations[i][0]-1].push_back(relations[i][1]-1);
            inDegree[relations[i][1]-1]++;
        }
        
        queue<int> Q;
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
                Q.push(i);
        }
        
        while (!Q.empty())
        {
            auto u = Q.front(); Q.pop();
            T[u] += time[u];
            
            for (auto v : G[u])
            {
                T[v] = max(T[u], T[v]);
                if (--inDegree[v] == 0)
                    Q.push(v);
            }
        }
        
        auto result = max_element(T.begin(), T.end());
        return *result;
    }
};