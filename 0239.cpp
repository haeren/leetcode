class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        map<int, int> window;
        
        for (int i = 0; i < k-1; i++)
            window[nums[i]]++;
        
        vector<int> result;
        
        for (int left = 0, right = k-1; right < nums.size(); left++, right++)
        {
            window[nums[right]]++;
            result.push_back(window.rbegin()->first);           
            auto iter = window.find(nums[left]);
            if (iter->second > 1)
                iter->second--;
            else
                window.erase(iter);
        }
        
        return result;
    }
};