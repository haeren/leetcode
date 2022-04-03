class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        #define DIFF(a, b) (abs((int64_t)a - (int64_t)b))

        if (nums.size() <= 1) return false;
        if (t < 0) return false;
        if (k <= 0) return false;

        set<int> numSet;
        numSet.insert(nums[0]);

        for (int i = 1; i < nums.size(); i++)
        {
            auto iter = numSet.upper_bound(nums[i]);
            if (iter != numSet.end() and DIFF(nums[i], *iter) <= t) return true;
            if (--iter != numSet.end() and DIFF(nums[i], *iter) <= t) return true;
            if (i - k >= 0) numSet.erase(nums[i-k]);
            numSet.insert(nums[i]);
        }

        return false;
    }
};