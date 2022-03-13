class Solution
{
public:
    /*
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int size = nums.size();
        for (int i = 0; i < size-1; i++)
            for (int j = i+1; j < size; j++)
                if (nums[i] + nums[j] == target)
                    return vector<int> {i,j};
        return vector<int> {-1,-1};
    }
    */
    
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int size = nums.size();
        int i = 0;
        int j = size - 1;
        int sum;
        
        vector<int> result;
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        do
        {
            sum = sorted[i] + sorted[j];
            if (sum > target)
                j--;
            else if (sum < target)
                i++;
        } while(sum != target);
        
        for (int k = 0; k < size; k++)
            if (nums[k] == sorted[i] or nums[k] == sorted[j])
                result.push_back(k);
        
        return result;
    }
};