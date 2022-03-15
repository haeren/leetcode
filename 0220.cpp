class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        int size = nums.size();
        if (size <= 1)
            return false;
        
        vector<pair<int,int>> numsWithIdx;
        
        for (int i = 0; i < size; i++)
            numsWithIdx.push_back({nums[i], i});
        
        sort(numsWithIdx.begin(), numsWithIdx.end());
        
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i+1; j < size; j++)
            {
                if (abs((int64_t)numsWithIdx[i].first - (int64_t)numsWithIdx[j].first) > t)
                    break;
                if (abs(numsWithIdx[i].second - numsWithIdx[j].second) <= k)
                    return true;
            }
        }
        return false;
    }
};