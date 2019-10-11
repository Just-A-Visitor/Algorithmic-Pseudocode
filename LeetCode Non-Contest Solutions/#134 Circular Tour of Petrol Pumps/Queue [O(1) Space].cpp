class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost);
};

int Solution :: canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    int n = gas.size();
    int size = 0, start = -1;
    
    int current = 0, fuel = 0, firstSeen = 0;

    while(true)
    {
        // This indicates that the last decision was incorrect
        if(fuel<0)
        {
            // Clear everything for fresh iterations
            fuel = 0;
            start = -1, size =0 ;
        }

        // Record how many time you encounter the first pump
        if(current==0) firstSeen++;

        // This is the third pass. Terminate!
        if(firstSeen>2) return -1;

        // Tour completed
        if(size==n)
            return start;

        // Enqueue the pump blindly
        fuel += gas[current];
        fuel -= cost[current];
        size++;
        
        // Update the first element if needed
        if(start==-1)
            start = current;
        
        // Go to the next pump
        current = (current + 1)%n;
    }
}
