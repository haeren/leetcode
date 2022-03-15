class Solution
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> result;
        int i = 0, j = 0;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        while (i < size1 and j < size2)
        {
            if (nums1[i] == nums2[j])
            {
                result.push_back(nums1[i]);
                i++;
                j++;
                
                // Skip if duplicate
                while (i < size1 and nums1[i] == nums1[i-1])
                    i++;
                while (j < size2 and nums2[j] == nums2[j-1])
                    j++;
            }
            else if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }  
        return result;
    }
};