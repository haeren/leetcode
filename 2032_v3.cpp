class Solution
{
public:
    void countFreqs(vector<int> &nums, unordered_map<int, int> &freq)
    {
        unordered_set<int> numSet;
        for (auto num : nums)
        {
            // The frequency of a number can be increased once for each vector
            // If a number is in at least two vectors, its frequency will be greater than one.
            if (numSet.count(num) > 0) continue;
            numSet.insert(num);
            freq[num]++;
        }
    }

    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3)
    {
        unordered_map<int, int> freq;
        countFreqs(nums1, freq);
        countFreqs(nums2, freq);
        countFreqs(nums3, freq);

        vector<int> result;
        for (auto iter : freq)
        {
            if (iter.second >= 2)
            result.push_back(iter.first);
        }

        return result;
    }
};