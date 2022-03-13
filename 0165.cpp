class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        stringstream ss1(version1);
        stringstream ss2(version2);
        string segment;
        vector<int> v1, v2;
        
        // Split version1 by '.'
        while (getline(ss1, segment, '.'))
            v1.push_back(stoi(segment));
        
        // Split version2 by '.'
        while (getline(ss2, segment, '.'))
            v2.push_back(stoi(segment));
        
        int size1 = v1.size();
        int size2 = v2.size();
        int diff = size1 - size2;
        
        // If the number of revisions are not equal, add zero(s) to end
        if (diff > 0)
            while(diff--)
                v2.push_back(0);
        else if (diff < 0)
            while(diff++)
                v1.push_back(0);
        
        // Compare
        int size = v1.size();
        for (int i = 0; i < size; i++)
        {
            if (v1[i] < v2[i])
                return -1;
            if (v1[i] > v2[i])
                return 1;
        }
        return 0;
    }
};