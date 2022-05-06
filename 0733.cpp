class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        int m = image.size();
        int n = image[0].size();
        vector<vector<char>> isVisited(m, vector<char>(n, 0));
        
        queue<pair<int, int>> myQ;        
        int initialColor = image[sr][sc];
               
        isVisited[sr][sc] = 1;
        image[sr][sc] = newColor;
        myQ.push({sr, sc});
        
        while(!myQ.empty())
        {
            auto [r, c] = myQ.front(); myQ.pop();
            vector<pair<int, int>> neighs = {{r, c-1}, {r, c+1}, {r-1, c}, {r+1, c}};
            
            for (auto [nr, nc] : neighs)
            {
                if (nr < 0 or nr == m or nc < 0 or nc == n)
                    continue;
                if (isVisited[nr][nc] == 0 and image[nr][nc] == initialColor)
                {
                    image[nr][nc] = newColor;
                    isVisited[nr][nc] = 1;
                    myQ.push({nr, nc});
                }
            }            
        }
        
        return image;
    }
};