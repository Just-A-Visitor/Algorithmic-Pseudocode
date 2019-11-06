class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost);
};

int Solution :: canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    int original_size = gas.size();
    for(int i = 0; i < original_size; i++)
    {
        gas.push_back(gas[i]);
        cost.push_back(cost[i]);
    }
    
    int new_size = original_size + original_size;
    
    queue<int> myQueue;
    
    int current = 0, fuel = 0;
    
    while(current < new_size)
    {
        // This indicates that the last decision was incorrect
        if(fuel<0)
        {
            // Clear everything for fresh iterations
            fuel = 0;
            while(!myQueue.empty())
                myQueue.pop();
        }

        // Tour completed
        if(myQueue.size() == original_size)
            return myQueue.front();   
        
        // Enqueue the pump blindly
        fuel += gas[current];
        fuel -= cost[current];
        myQueue.push(current);
        
        // Go to the next pump
        current++;
    }
           
    return -1;
}
