class Solution
{
public:
    int reverse(int x)
    {
        if (x == INT_MIN)
            return 0;   // if x == INT_MIN, return 0 to prevent the overflow when converting to positive
        bool isNegative = x < 0;
        if (isNegative)
            x = -x;
        
        int result = 0;
        int digit;
        
        while (x > 0)
        {
            digit = x % 10;            
            if (result > (INT_MAX - digit)/10)
                return 0;   // result * 10 + digit <= INT_MAX, if not return 0
            result = result * 10 + digit;
            x /= 10;
        }
        return isNegative ? -result : result;
    }
};