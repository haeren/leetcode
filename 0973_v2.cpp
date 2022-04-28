class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        priority_queue<pair<int, int>> myBinHeap;
        
        for (int i = 0; i < points.size(); i++)
        {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            
            if (myBinHeap.size() < k)
                myBinHeap.push({dist, i});
            else if (dist < myBinHeap.top().first)
            {
                myBinHeap.pop();
                myBinHeap.push({dist, i});
            }
        }
        
        vector<vector<int>> result;
        
        while (!myBinHeap.empty())
        {
            result.push_back(points[myBinHeap.top().second]);
            myBinHeap.pop();
        }
        
        return result;
    }
};