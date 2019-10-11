var isValid = function (str)
{
    var pattern = "abc";
    
    var position = str.indexOf(pattern);
    
    while(position != -1)
    {
        // Remember to overwrite the string
        str = str.replace(pattern, "");
        position = str.indexOf(pattern);
    }
    
    return str.length==0;
}
