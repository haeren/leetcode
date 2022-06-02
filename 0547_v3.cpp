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
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();
        DisjointSet ds(n);
        
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if (isConnected[i][j])
                {
                    int set1 = ds.find(i);
                    int set2 = ds.find(j);
                    ds.join(set1, set2);
                }
            }
        }
        
        return ds.setCount();
    }
};