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
    int makeConnected(int n, vector<vector<int>>& connections)
    {
        DisjointSet ds(n);
        int numOfSets = n;
        int numOfRedundantCables = 0;
        
        for (int i = 0; i < connections.size(); i++)
        {
            int set1 = ds.find(connections[i][0]);
            int set2 = ds.find(connections[i][1]);
            
            if (set1 == set2)
                numOfRedundantCables++;
            else
            {
                ds.join(set1, set2);
                numOfSets--;
            }               
        }
        
        int numOfCablesNeeded = numOfSets - 1;
        if (numOfCablesNeeded > numOfRedundantCables) return -1;
        return numOfCablesNeeded;
    }
};