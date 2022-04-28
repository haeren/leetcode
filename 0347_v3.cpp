class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> myMap;
        
        for (auto num : nums)
            myMap[num]++;
        
        int maxFreq = 0;
        for (auto [num, freq] : myMap)
            if (freq > maxFreq)
                maxFreq = freq;
        
        vector<vector<int>> freqs(maxFreq+1);
        for (auto [num, freq] : myMap)
            freqs[freq].push_back(num);
        
        vector<int> result;
        for (int i = maxFreq; k > 0 and i >= 0; i--)
            for (int j = 0; j < freqs[i].size() and k > 0; j++, k--)
                result.push_back(freqs[i][j]);
        
        return result;
    }
};