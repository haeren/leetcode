class Solution
{
public:
    int calculate(string s)
    {
        stack<int> stk;
        int result = 0;
        int multiplier = 1;
        
        for (int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]))
            {
                int temp = 0;
                
                while (i < s.length() and isdigit(s[i]))
                {
                    temp *= 10;
                    temp += s[i] - '0';
                    i++;
                }
                
                i--;
                result += multiplier * temp;
            }
            else if (s[i] == '+') multiplier = 1;
            else if (s[i] == '-') multiplier = -1;
            else if (s[i] == '(')
            {
                stk.push(result);
                stk.push(multiplier);
                result = 0;
                multiplier = 1;
            }
            else if (s[i] == ')')
            {
                result *= stk.top();
                stk.pop();
                result += stk.top();
                stk.pop();
            }
        }
        
        return result;
    }
};