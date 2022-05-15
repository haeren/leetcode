class Solution
{
public:
    int lastStoneWeight(vector<int>& stones)
    {       
        priority_queue<int> remainings;
        for (auto stone : stones)
            remainings.push(stone);
        
        while (!remainings.empty())
        {
            if (remainings.size() == 1)
                return remainings.top();
            
            int heaviest1 = remainings.top();
            remainings.pop();
            int heaviest2 = remainings.top();
            remainings.pop();
            
            int diff = heaviest1 - heaviest2;
            if (diff > 0)
                remainings.push(diff);
        }
        
        return 0;
    }
};