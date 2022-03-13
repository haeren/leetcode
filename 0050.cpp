class Solution
{
public:
    double powIter(double x, int n) // Time Limit Exceeded
    {
        double result = 1.0;
        while(n--)
            result *= x;
        return result;
    }
    
    double powDivConq(double x, int n)
    {
        if (n == 0)
            return 1.0;
        if (n == 1)
            return x;
        
        double partial = powDivConq(x,n/2);
        double result = partial * partial;
        
        if (n%2 == 1)
            result *= x;
        
        return result;
    }
    
    double powBit(double x, int n)
    {
        double result = 1.0;
        double multiplier = x;
        
        while(n > 0)
        {
            if (n & 0x1)
                result *= multiplier;
            n >>= 1;
            multiplier *= multiplier;
        }
        return result;
    }
      
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1.0;
        if (x == 1)
            return 1.0;
        if (x == -1)
            return n%2 == 0 ? 1.0 : -1.0;
        
        bool isNegative = false;
        if (n < 0)
        {
            n = -(n+1); // Increase n by 1 to avoid overflow since -2^31 <= n <= 2^31-1
            isNegative = true;
        }
        
        // double result = powIter(x,n);
        // double result = powDivConq(x,n);
        double result = powBit(x,n);
        return isNegative ? 1.0/(result*x) : result;       
    }
};