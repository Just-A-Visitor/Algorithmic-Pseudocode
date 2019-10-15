class Solution
{
public:
    vector<bool> prefixesDivBy5(vector<int>& a);
};

vector<bool> Solution :: prefixesDivBy5(vector<int>& a)
{
    vector<bool> answer;
    int num=0;
    for(int i=0; i<a.size(); i++)
    {
        num = (num*2 + a[i])%5;
        answer.push_back(num==0);
    }
    return answer;
}
