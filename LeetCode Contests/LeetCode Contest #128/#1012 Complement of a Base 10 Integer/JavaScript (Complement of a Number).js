var bitwiseComplement = function(num)
{
    var all_bits_set = Math.pow(2,0);
    for(let i=1; all_bits_set<num; i++)
        all_bits_set += Math.pow(2,i);
    
    return num ^ all_bits_set;
};
