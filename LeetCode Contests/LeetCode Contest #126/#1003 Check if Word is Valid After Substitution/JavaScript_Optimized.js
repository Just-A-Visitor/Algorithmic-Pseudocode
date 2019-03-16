var isValid = function(str)
{
    var stack = [];
    var n;
    
	// Traverse the string and keep deleting 'abc' in O(1)
    for(let i=0; i<str.length; i++)
    {
        n = stack.length;
        var ele = str[i];
        
		// If the character is 'c', pop the matching 'b' and 'a' from the stack, if they exist 
        if(ele!= 'c' || stack.length==0) stack.push(ele);
        else
            if(stack.length>=2 && stack[n-1]=='b' && stack[n-2]=='a')
                stack.pop(), stack.pop();
    }
    
    return stack.length==0;
}
