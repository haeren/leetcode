class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        vector<pair<int, int>> distances;
        for (int i = 0; i < points.size(); i++)
        {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            distances.push_back({dist, i});
        }
        
        sort(distances.begin(), distances.end());
        
        vector<vector<int>> result;
        for (int i = 0; i < k; i++)
            result.push_back(points[distances[i].second]);
        
        return result;    
    }
};