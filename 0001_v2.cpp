class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        //           <num, index>
        unordered_map<int, int> otherNumMap;

        for (int i = 0; i < nums.size(); i++)
        {
            int otherNum = target - nums[i];
            auto iter = otherNumMap.find(otherNum);
            if (iter != otherNumMap.end())
                return {iter->second, i};
            else
                otherNumMap.insert({nums[i], i});
        }

        return {-1, -1};
    }
};