class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set<int> numSet;

        for (auto num: nums)
        {
            if (numSet.count(num) != 0)
                return true;
            else
                numSet.insert(num);
        }

        return false;
    }
};