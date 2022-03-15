class Solution
{
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(),
             [](vector<int> &a, vector<int> &b){return a[1] > b[1];});
        
        int total = 0;
        int size = boxTypes.size();
        
        for (int i = 0; i < size; i++)
        {
            int numBoxes = boxTypes[i][0];
            int numUnits = boxTypes[i][1]; 
            int taken = min(numBoxes, truckSize);
            total += taken * numUnits;
            truckSize -= taken;
            if (truckSize == 0)
                break;
        }
        
        return total;
    }
};