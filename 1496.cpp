class Solution
{
public:
    string intPairToStr(int x, int y)
    {
        return to_string(x) + ',' + to_string(y);
    }
    
    bool isPathCrossing(string path)
    {
        int length = path.length();        
        if (length == 1)
            return false;
             
        pair<int,int> coordinate = {0,0};
        unordered_set<string> visited;
        visited.insert(intPairToStr(coordinate.first, coordinate.second));
        int size = 1;
        
        for (int i = 0; i < length; i++)
        {
            if (path[i] == 'N')
                coordinate.second++;
            else if (path[i] == 'S')
                coordinate.second--;
            else if (path[i] == 'E')
                coordinate.first++;
            else
                coordinate.first--;
            
            visited.insert(intPairToStr(coordinate.first, coordinate.second));
            if (visited.size() == size)
                return true;
            size++;
        }
        return false;
    }
};