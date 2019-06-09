class Solution
{
public:
    void rotate(vector<int>& v, int k);
};

/* Rotates the array to the right by K */
void Solution :: rotate(vector<int>& v, int k)
{
    // Extract size and normalize the shift
    int n = v.size();
    k = k%n;
    
    // Reverse the entire array
    reverse(v.begin(), v.end());
    
    // Reverse first k elements
    reverse(v.begin(), v.begin() + k);
    
    // Reverse the last (n-k) elements
    reverse(v.begin()+k, v.end());
}
