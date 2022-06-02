class Solution
{
    void dfs(string &u, unordered_map<string, vector<string>> &G, vector<string> &result)
    {
        while (G[u].size())
        {
            auto v = G[u].back(); G[u].pop_back();
            dfs(v, G, result);
        }
        
        result.push_back(u);
    }
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets)
    {
        unordered_map<string, vector<string>> G;
        for (auto &ticket : tickets)
        {
            string &from = ticket[0];
            string &to = ticket[1];
            G[from].push_back(to);
        }
        
        for (auto &[from, to] : G)
            sort(to.begin(), to.end(), greater());
        
        vector<string> result;
        string start = "JFK";
        dfs(start, G, result);
        reverse(result.begin(), result.end());
        return result;
    }
};