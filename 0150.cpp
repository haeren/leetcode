class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> operands;

        for (auto token : tokens)
        {
            if (token.length() == 1 and !isdigit(token[0]))
            {
                int operand2 = operands.top(); operands.pop();
                int operand1 = operands.top(); operands.pop();
                int result;

                switch(token[0])
                {
                    case '+': result = operand1 + operand2;
                        break;
                    case '-': result = operand1 - operand2;
                        break;
                    case '*': result = operand1 * operand2;
                        break;
                    case '/': result = operand1 / operand2;
                        break;
                }

                operands.push(result);
            }
            else
                operands.push(stoi(token));
        }

        return operands.top();
    }
};