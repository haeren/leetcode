class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        int num = nums[0];
        int freq = 1;
        vector<pair<int, int>> freqs;
        
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == num)
                freq++;
            else
            {
                freqs.push_back({freq, num});
                num = nums[i];
                freq = 1;
            }
        }
        
        freqs.push_back({freq, num});
        
        sort(freqs.begin(), freqs.end(), greater());

        vector<int> result;
        for (int i = 0; i < k; i++)
            result.push_back(freqs[i].second);
        
        return result;
    }
};