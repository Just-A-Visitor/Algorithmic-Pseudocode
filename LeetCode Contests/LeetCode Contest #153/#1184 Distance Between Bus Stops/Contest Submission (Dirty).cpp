class Solution
{
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination);
};

int Solution :: distanceBetweenBusStops(vector<int>& dist, int start, int destination)
{
    int n = dist.size();
    int current = start;
    int forward = 0;
    while(true)
    {
        forward += dist[current];
        current = (current + 1)%n;
        if(current == destination)
            break;
        
        
    }
    
    int backward = 0;
    current = start;
    
    while(true)
    {
        current = (current) ? current - 1 : n-1;
        backward += dist[current];
        
        if(current == destination)
            break;
        
        
    }
    
    return min(forward, backward);
}
