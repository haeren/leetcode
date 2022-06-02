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
    
    int size(int u)
    {
        return -sets[u];
    }
};

class Solution
{
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        DisjointSet ds(n);
        
        for (int i = 0; i < edges.size(); i++)
        {
            int set1 = ds.find(edges[i][0]);
            int set2 = ds.find(edges[i][1]);
            ds.join(set1, set2);
        }
        
        return ds.find(source) == ds.find(destination);
    }
};