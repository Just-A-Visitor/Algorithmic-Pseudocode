class Solution 
{
public:
    bool queryString(string S, int N);
};

bool Solution :: queryString(string str, int N)
{
    for(int i=1; i<=N; i++)
    {
        int number = i;
        string str_num = "";
		
        // Convert the number to string
        while(number!=0)
        {
            str_num += number%2 + '0';
            number = number/2;
        }
        
        // Reverse the string to get the correct representation
        reverse(str_num.begin(), str_num.end());
        
        // Check if the number is present or not
        if(str.find(str_num)==string::npos) 
            return false;
    }
    
    return true;
}
