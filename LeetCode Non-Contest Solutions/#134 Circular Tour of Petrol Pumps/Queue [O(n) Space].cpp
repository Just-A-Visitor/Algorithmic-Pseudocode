class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost);
};

int Solution :: canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    int n = gas.size();
    queue<int> myQueue;
    
    int current = 0, fuel = 0, firstSeen = 0;

    while(true)
    {
        // This indicates that the last decision was incorrect
        if(fuel<0)
        {
            // Clear everything for fresh iterations
            fuel = 0;
            while(!myQueue.empty())
                myQueue.pop();
        }

        // Record how many time you encounter the first pump
        if(current==0) firstSeen++;

        // This is the third pass. Terminate!
        if(firstSeen>2) return -1;

        // Tour completed
        if(myQueue.size()==n)
            return myQueue.front();   

        // Enqueue the pump blindly
        fuel += gas[current];
        fuel -= cost[current];
        myQueue.push(current);
        
        // Go to the next pump
        current = (current + 1)%n;
    }
}
