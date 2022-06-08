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
};

class Solution
{   
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int n = edges.size();
        DisjointSet ds(n);
        
        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int set1 = ds.find(u-1);
            int set2 = ds.find(v-1);
            
            if (set1 == set2) return {u, v};
            else              ds.join(set1, set2);
        }
        
        return {-1, -1};
    }
};