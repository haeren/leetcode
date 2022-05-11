class Solution
{
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3)
    {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int size3 = nums3.size();
        vector<int> result;
        
        for (int i = 0; i < size1; i++)
        {
            for (int j = 0; j < size2; j++)
            {
                if (nums1[i] == nums2[j])
                {
                    if (find(result.begin(), result.end(), nums2[j]) == result.end())
                        result.push_back(nums2[j]);
                    break;
                }
            }
            for (int j = 0; j < size3; j++)
            {
                if (nums1[i] == nums3[j])
                {
                    if (find(result.begin(), result.end(), nums3[j]) == result.end())
                        result.push_back(nums3[j]);
                    break;
                }
            }
        }
        
        for (int i = 0; i < size2; i++)
        {
            for (int j = 0; j < size3; j++)
            {
                if (nums2[i] == nums3[j])
                {
                    if (find(result.begin(), result.end(), nums3[j]) == result.end())
                        result.push_back(nums3[j]);
                    break;
                }
            }
        }
        
        return result;
    }
};
