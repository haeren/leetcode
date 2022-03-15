class Solution
{
public:
    static int numBits(int x)
    {
        int count = 0;
        while (x > 0)
        {
            if (x & 0x1)
                count++;
            x >>= 1;
        }
        return count;
    }
    
    vector<int> sortByBits(vector<int>& arr)
    {
        auto isLower = [](int x, int y)
        {
            int count1 = numBits(x);
            int count2 = numBits(y);
            
            if (count1 == count2)
                return x < y;
            return count1 < count2;
        };
        
        sort(arr.begin(), arr.end(), isLower);
        return arr;
    }
};