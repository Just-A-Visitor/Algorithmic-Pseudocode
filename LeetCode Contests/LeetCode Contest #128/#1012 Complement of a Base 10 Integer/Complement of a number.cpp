class Solution
{
public:
    int bitwiseComplement(int n);
};

int Solution :: bitwiseComplement(int num)
{
    int all_bits_set = pow(2,0);
    for(int i=1; all_bits_set<num; i++)
        all_bits_set += pow(2,i);
    
    return num xor all_bits_set;
}
