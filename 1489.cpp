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
    
    int setCount()
    {
        int count = 0;
        for (int i = 0; i < sets.size(); i++)
            if (sets[i] < 0) count++;
        return count;
    }
};

class Solution
{
    int mstWeight(int n, vector<vector<int>>& edges, int ignoredEdge, int includedEdge)
    {        
        DisjointSet ds(n);
        int weight = 0;
        
        if (includedEdge != -1)
        {
            weight += edges[includedEdge][2];
            ds.join(edges[includedEdge][0], edges[includedEdge][1]);
        }
        
        for (int i = 0; i < edges.size(); i++)
        {
            if (i == ignoredEdge) continue;
            int set1 = ds.find(edges[i][0]);
            int set2 = ds.find(edges[i][1]);
            
            if (set1 != set2)
            {
                weight += edges[i][2];
                ds.join(set1, set2);
            }
        }
        
        return ds.setCount() == 1 ? weight : INT_MAX;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges)
    {
        for (int i = 0; i < edges.size(); i++)
            edges[i].push_back(i); // Push edge index (u, v, weight, index)
        sort(edges.begin(), edges.end(), [&](vector<int> left, vector<int> right)
             {return left[2] < right[2];});  // Sort by weights
                
        int initialWeight = mstWeight(n, edges, -1, -1);
        vector<int> critical;
        vector<int> pseudoCritical;
        
        for (int i = 0; i < edges.size(); i++)
        {            
            if (mstWeight(n, edges, i, -1) > initialWeight)
            {
                critical.push_back(edges[i][3]);
            }
            else if (mstWeight(n, edges, -1, i) == initialWeight)
            {
                pseudoCritical.push_back(edges[i][3]);
            }
        }
        
        return {critical, pseudoCritical};
    }
};