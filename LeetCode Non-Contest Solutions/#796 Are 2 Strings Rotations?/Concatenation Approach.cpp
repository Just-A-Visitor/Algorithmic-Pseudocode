class Solution 
{
    public:
    bool rotateString(string text, string pattern) 
    {
        // Rotating strings does not change their length
        if(text.length()!=pattern.length()) return false;
        
        // Concatenate the first string to itself to get the rid of circular searching
        string concatenatedString = text + text;
        
        // If it is a rotation, then it must occur as a substring of the concatenated string
        if(concatenatedString.find(pattern) != string::npos) return true;
        else return false;
    }
};
