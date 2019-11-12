## Review
It's just a fancy way to avoid braces while printing a matrix. Use it only if you are comfortable with it. It might look cryptic at first, but once you understand the concept, it's very easy. 

## Why does it Work?
`" \n"` is a `char*`. Let's call it `str`. So, `str[0]` gives us ` `, while `str[1]` gives us `\n`. Now, `str[false]` gives us a space while `str[true]` gives us a new line. Hence, we get the appropriate spacing after each row.
