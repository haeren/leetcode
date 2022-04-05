class Solution
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        stack<int> s;
        unordered_map<int, int> nextGreater;
        
        for (int i = nums2.size()-1; i >=0; i--)
        {
            while (!s.empty() and nums2[i] >= s.top())
                s.pop();
            
            if (s.empty())
                nextGreater[nums2[i]] = -1;
            else
                nextGreater[nums2[i]] = s.top();
            
            s.push(nums2[i]);
        }
        
        vector<int> result;
        for (int i = 0; i < nums1.size(); i++)
            result.push_back(nextGreater[nums1[i]]);
        
        return result;
    }
};