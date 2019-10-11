/* This solution assumes that atleast 1 posiitve element is present */
/* Fails on LeetCode */
class Solution
{
public:
    int maxProduct(vector<int>& a);
};

int Solution ::  maxProduct(vector<int>& a)
{
    int max_ending_here = 1;
    int min_ending_here = 1;

    int max_so_far = INT_MIN;

    for(int i=0; i<n; i++)
    {
        if(a[i]>0)
        {
            max_ending_here *= a[i];
            min_ending_here = min(min_ending_here*a[i], 1);
        }

        if(a[i]==0)
        {
            max_ending_here = 1;
            min_ending_here = 1;
        }

        if(a[i]<0)
        {
            int temp = max_ending_here;
            max_ending_here = max(min_ending_here*a[i], 1);
            min_ending_here = temp*a[i];
        }

        max_so_far = max(max_so_far, max_ending_here);
    }
}
