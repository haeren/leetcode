class Solution
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        vector<pair<int,int>> numsWithIdx;
        int size = nums.size();
        
        for (int i = 0; i < size; i++)
            numsWithIdx.push_back({nums[i], i});
        
        sort(numsWithIdx.begin(), numsWithIdx.end());
        
        for (int i = 1; i < size; i++)
            if (numsWithIdx[i].first == numsWithIdx[i-1].first)
                if (abs(numsWithIdx[i].second - numsWithIdx[i-1].second) <= k)
                    return true;
        return false;
    }
};