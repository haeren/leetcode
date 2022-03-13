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
        int i = 0;
        int j = nums.size() - 1;
        int sum;

        do
        {
            sum = nums[i] + nums[j];
            if (sum > target)
                j--;
            else if (sum < target)
                i++;
        } while(sum != target);
        
        return vector<int> {i+1, j+1};
    }
};