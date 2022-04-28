class Solution
{
public:
    static bool sortByDiff(const vector<int>& v1, const vector<int>& v2)
    {
        return abs(v1[0]-v1[1]) >= abs(v2[0]-v2[1]);
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs)
    {
        int minCost = 0;
        int a = 0, b = 0;
        int n = costs.size()/2;
        
        sort(costs.begin(), costs.end(), sortByDiff);
        
        for (auto it = costs.begin(); it != costs.end(); it++)
        {
            if (a == n)
                minCost += (*it)[1];
            else if (b == n)
                minCost += (*it)[0];
            else if ((*it)[0] < (*it)[1])
            {
                a++;
                minCost += (*it)[0];
            }
            else
            {
                b++;
                minCost += (*it)[1];
            }
        }        
        return minCost;
    }
};