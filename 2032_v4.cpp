class Solution
{
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3)
    {
        int maxNum = 100;

        vector<int> lookupTable1(maxNum+1);
        for (auto num : nums1) lookupTable1[num] = 1;

        vector<int> lookupTable2(maxNum+1);
        for (auto num : nums2) lookupTable2[num] = 1;

        vector<int> lookupTable3(maxNum+1);
        for (auto num : nums3) lookupTable3[num] = 1;

        vector<int> result;
        
        for (int num = 1; num <= maxNum; num++)
        {
            int count = lookupTable1[num] + lookupTable2[num] + lookupTable3[num];
            if (count >= 2)
                result.push_back(num);
        }
        
        return result;
    }
};