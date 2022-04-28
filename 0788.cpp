class Solution
{
public:
    bool isGood(int n)
    {
        int rotateMap[] = {0,1,5,-1,-1,2,9,-1,8,6};
        int number = n;
        int remainder, rotatedDigit;
        int rotated = 0, multiplier = 1;
        
        while (number)
        {
            remainder = number % 10;
            rotatedDigit = rotateMap[remainder];
            if (rotatedDigit == -1)
                return false;
            rotated += rotatedDigit * multiplier;
            multiplier *= 10;
            number /= 10;
        }

        if (rotated == n)
            return false;
        return true;
    }

    int rotatedDigits(int n)
    {
        int counter = 0;
        
        while (n)
        {
            if (isGood(n))
                counter++;
            n--;
        }

        return counter;
    }
};