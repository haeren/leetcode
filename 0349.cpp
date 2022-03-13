class Solution
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> result;
        
        for (int i = 0; i < size1; i++)
            for (int j = 0; j < size2; j++)
                if (nums1[i] == nums2[j])
                {
                    if (find(result.begin(), result.end(), nums2[j]) == result.end())
                        result.push_back(nums2[j]);
                    break;
                }        
        return result;
    }
};