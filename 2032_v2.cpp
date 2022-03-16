class Solution
{
public:
    void intersect(vector<int> &v1, vector<int> &v2, vector<int> &result)
    {
        int size1 = v1.size();
        int size2 = v2.size();
        int i = 0, j = 0;
        
        while (i < size1 and j < size2)
        {
            if (v1[i] == v2[j])
            {
                result.push_back(v1[i]);
                i++;
                j++;
            }
            else if (v1[i] < v2[j])
                i++;
            else
                j++;
        }
    }
    
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        sort(nums3.begin(), nums3.end());
        
        vector<int> result;
        
        intersect(nums1, nums2, result);
        intersect(nums1, nums3, result);
        intersect(nums2, nums3, result);
        
        if (result.size() <= 1)
            return result;
        
        sort(result.begin(), result.end());
        auto iterUniqueEnd = unique(result.begin(), result.end());
        result.resize(iterUniqueEnd - result.begin());

        return result;
    }
};