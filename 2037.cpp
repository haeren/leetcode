class Solution
{
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students)
    {
        sort(students.begin(), students.end());
        sort(seats.begin(), seats.end());
        
        int size = students.size();
        int result = 0;
        
        for (int i =0; i < size; i++)
            result += abs(students[i] - seats[i]);
            
        return result;
    }
};