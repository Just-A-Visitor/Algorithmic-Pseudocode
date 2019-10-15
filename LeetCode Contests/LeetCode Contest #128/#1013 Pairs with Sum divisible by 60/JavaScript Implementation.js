/* Returns the number of pairs whose sum is divisible by 60 */
var numPairsDivisibleBy60 = function(time)
{
    // The reference for modular arithmetic
    const ref=60;
	
    // Initilize the map
    var count = [];
    for(let i=0; i<ref; i++)
        count.push(0);
    
    // Populate the map in modular arithemtic
    for(let i=0; i<time.length; i++)
        count[time[i]%ref]++;
		
    // Traverse from 1 to 29 and update answer
    var answer = 0;
    for(let i=1; i<ref/2; i++)
        answer += count[i]*count[ref-i];
		
    // Deal with numbers with identical complement
    answer += count[0]*(count[0]-1)/2;
    answer += count[ref/2]*(count[ref/2]-1)/2;
    
    return answer;
}
