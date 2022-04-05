class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        deque<int> indices;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++)
        {
            // Pop the leftmost element if the window is full
            if (indices.size() and indices.front() <= i-k)
                indices.pop_front();
            
            // Pop the numbers that do not have the potential to be maximum
            while (indices.size() and nums[i] > nums[indices.back()])
                indices.pop_back();
                
            indices.push_back(i);
            
            // Push the maximum to the result vector if window size is k
            if (i >= k-1)
                result.push_back(nums[indices.front()]);
        }
        
        return result;
    }
};