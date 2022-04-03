class Solution
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        int maxNum = 1000;
        vector<int> lookupTable(maxNum+1, 0);

        for (auto num : nums1)
            lookupTable[num] = 1;

        vector<int> result;
        for (auto num : nums2)
        {
            if (lookupTable[num] == 1)
            {
                result.push_back(num);
                lookupTable[num] = 0;   // Avoid duplicate numbers in the result vector
            }
        }

        return result;
    }
};