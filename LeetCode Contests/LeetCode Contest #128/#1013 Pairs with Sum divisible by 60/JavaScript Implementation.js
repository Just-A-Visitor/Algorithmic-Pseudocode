var numPairsDivisibleBy60 = function(time)
{
    const ref=60;

    var count = [];
    for(let i=0; i<ref; i++)
        count.push(0);
    
    for(let i=0; i<time.length; i++)
        count[time[i]%ref]++;
    
    var answer = 0;
    for(let i=1; i<ref/2; i++)
        answer += count[i]*count[ref-i];
    
    answer += count[0]*(count[0]-1)/2;
    answer += count[ref/2]*(count[ref/2]-1)/2;
    
    return answer;
}
