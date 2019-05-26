class Solution
{
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes);
};

vector<int> Solution :: rearrangeBarcodes(vector<int>& a)
{
    // Vector to store the final answer
    vector<int> answer;

    // Update the frequency of each character
    unordered_map<int, int> myMap;
    for(auto ele : a)
        myMap[ele]++;
    
    // Priority queue to store the elements by frequency
    priority_queue<pair<int,int>, vector<pair<int,int>>> maxHeap;

    // Populate the max Heap. Frequency is the first field, value is second
    for(auto ele : myMap)
        maxHeap.push(make_pair(ele.second, ele.first));
    
    pair<int,int> previous = {0,0};
    while(!maxHeap.empty())
    {
        // Extract the top element
        auto topElement = maxHeap.top();
        maxHeap.pop();

        // Interleave it
        answer.push_back(topElement.second);

        // Push the previously pulled element
        if(previous.first>0)
            maxHeap.push(previous);

        // Used once, reduce frequency and update previous
        topElement.first = topElement.first - 1;
        previous = topElement;
    }

    // Return the populated vector
    return answer;
}
