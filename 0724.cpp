class Solution
{
public:
    int pivotIndex(vector<int>& nums)
    {
        int left = 0;
        int right = accumulate(nums.begin(), nums.end(), 0);

        for (auto it = nums.begin(); it != nums.end(); it++)
        {
            right -= *it;

            if (left == right)
            {
                int index = distance(nums.begin(), it);
                return index;
            }
            left += *it;
        }
        return -1;
    }
};