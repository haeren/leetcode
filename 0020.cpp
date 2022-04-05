class Solution
{
public:
    bool isValid(string s)
    {
        unordered_set<char> openBrackets = {'(', '[', '{'};
        unordered_map<char, char> bracketMap = {{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> bracketStack;

        for (auto ch : s)
        {
            if (openBrackets.count(ch) != 0)
                bracketStack.push(ch);
            else if (!bracketStack.empty() and bracketMap[ch] == bracketStack.top())
                bracketStack.pop();
            else
                return false;
        }

        return bracketStack.empty();
    }
};