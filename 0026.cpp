class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int size = nums.size();
        if (size <= 1)
            return size;
        
        int counter = 0;
        for (int i = 1; i < size; i++)
            if (nums[i] != nums[counter])
                nums[++counter] = nums[i];
        
        return counter + 1;
    }
};