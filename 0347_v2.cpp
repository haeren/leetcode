class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> myMap;
        
        for (auto num : nums)
            myMap[num]++;
        
        // Min-heap
        auto cmp = [](pair<int, int> &left, pair<int, int> &right)
        {
            return (left.first >= right.first);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> PQ(cmp);
        
        for (auto [num, freq] : myMap)
        {
            if (PQ.size() < k)
                PQ.push({freq, num});
            else if (freq > PQ.top().first)
            {
                PQ.pop();
                PQ.push({freq, num});
            }
        }
        
        vector<int> result;
        while (!PQ.empty())
        {
            auto [freq, num] = PQ.top(); PQ.pop();
            result.push_back(num);
        }
        
        return result;
    }
};