class Solution
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        int size1 = nums1.size();
        int size2 = nums2.size();
        stack<int> s;
        vector<int> nextGreater(size2);
        
        for (int i = size2-1; i >= 0; i--)
        {
            while (!s.empty() and nums2[i] >= s.top())
                s.pop();
            
            if (s.empty())
                nextGreater[i] = -1;
            else
                nextGreater[i] = s.top();
            
            s.push(nums2[i]);
        }
        
        vector<int> result;
        
        for (int i = 0; i < size1; i++)
        {
            for (int j = 0; j < size2; j++)
            {
                if (nums1[i] == nums2[j])
                {
                    result.push_back(nextGreater[j]);
                    break;
                }
            }
        }
        
        return result;
    }
};