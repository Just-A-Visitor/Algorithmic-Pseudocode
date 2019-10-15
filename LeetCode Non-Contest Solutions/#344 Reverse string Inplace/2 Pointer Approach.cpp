class Solution
{
    public:
    void reverseString(vector<char>& str);
};

void Solution :: reverseString(vector<char>& str)
{
    int len = str.size();
    
    // If the string is of length less than two, it is already in place
    if(len<2) return;
    
    // Use the two pointer approach. Start Swapping element from the front and back
    int left = 0;
    int right = len-1;
    
    // Temporary buffer to store the element to be swapped
    char buffer;
    
    // While left does not cross rght, keep swapping
    while(left<right)
    {
        // Store the left element in the buffer
        buffer = str[left];
        
        // Overwrite the left element with the right element
        str[left] = str[right];
        
        // Overwrite the right element with the buffer
        str[right] = buffer;
        
        // Move left forward and right backwards to continue the process
        left++;
        right--;
    }
}
