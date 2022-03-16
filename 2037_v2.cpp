class Solution
{
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students)
    {
        #define MAX_NUM 101
        vector<int> seatCounts(MAX_NUM, 0);
        vector<int> studentCounts(MAX_NUM, 0);
        
        // Counting sort
        for (auto seat : seats)
            seatCounts[seat]++;
        
        for (auto student : students)
            studentCounts[student]++;
        
        for (int i = 0, k = 0; i < MAX_NUM; i++)
            while (seatCounts[i]-- > 0)
                seats[k++] = i;
            
        for (int i = 0, k = 0; i < MAX_NUM; i++)
            while (studentCounts[i]-- > 0)
                students[k++] = i;
        
        int result = 0;
        int size = students.size();
        
        for (int i = 0; i < size; i++)
            result += abs(seats[i] - students[i]);
        
        return result;
    }
};