class Solution
{
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int targetLevel)
    {
        #define WHITE 0
        #define BLACK 1
        
        int n = friends.size();
        vector<char> color(n, WHITE);
        vector<int> level(n, 0);
        queue<int> Q;
        vector<int> targetFriend;
        
        Q.push(id);
        color[id] = BLACK;
        
        while(!Q.empty())
        {
            int u = Q.front(); Q.pop();
            
            for (int &f : friends[u])
            {
                if (color[f] == WHITE)
                {
                    Q.push(f);
                    level[f] = level[u] + 1;
                    color[f] = BLACK;
                }
            }
            
            if (level[u] == targetLevel)
                targetFriend.push_back(u);
            else if (level[u] > targetLevel)
                break;
        }
        
        unordered_map<string, int> videoMap;
        for (int &t : targetFriend)
        {
            for (string &v : watchedVideos[t])
            {
                videoMap[v]++;
            }
        }
        
        vector<pair<int, string>> videoVector;
        for (auto &[video, freq] : videoMap)
            videoVector.push_back({freq, video});        
        sort(videoVector.begin(), videoVector.end());
        
        vector<string> result;
        for (auto &[freq, video] : videoVector)
            result.push_back(video);
        
        return result;
    }
};