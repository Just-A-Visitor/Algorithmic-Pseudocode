#include <stdio.h>
#include <iostream>
using namespace std;
/* Check for the size limits at the end, if error persists */ 
# define stack_size 100000
# define max_string_size 100000
# define max_token_size 100000

template <typename all_data_types>
class Stack
{
    //set the access to public to allow smooth access to everybody
    public:
    
    //The stack class contains 2 members, an integer array, and an integer top
    all_data_types arr[stack_size];
    int top;
    
    //This member function pushes the key onto the stack, by first advancing the top pointer
    void push(all_data_types key)
    {
        top++;
        arr[top]=key;
    }
    
    //Pops the top element by decreasing the pointer first and then returning the previous element
    all_data_types pop()
    {
        top--;
        return arr[top+1];
    }
    
    //Checks if the stack is empty or not
    int isEmpty()
    {
        if(top<0) return 1;
        else return 0;
    }
    
    //Checks if the stack is full or not
    int isFull()
    {
        if(top==stack_size-1)  return 1;
        else return 0;
    }
    
    //Returns the top element without popping it
    all_data_types peek()
    {
        return arr[top];
    }
    
};    // Remember the semi colon, just like structure

//The token structure to record the the types and values
struct Token
{
    int tk_type;
    int tk_val;
};

//Stores a pair
struct Pair
{
    int first;
    int second;
};

//Returns a to the power b
int power(int a, int b)
{
    int power=1;
    for(int i=0; i<b; i++)
    {
        power=power*a;
    }
    return power;
}

//Assigns an integer code to each operator, integer's code is 0
int convert_op_to_int(char check)
{
    if(check=='+') return 1;
    if(check=='-') return 2;
    if(check=='*') return 3;
    if(check=='/') return 4;
    if(check=='%') return 5;
    if(check=='^') return 6;
    if(check=='~') return 7;
    else return 0;
    
}

//DeReferences the code to get the operator
char convert_int_to_op(int check)
{
    if(check==1) return '+';
    if(check==2) return '-';
    if(check==3) return '*';
    if(check==4) return '/';
    if(check==5) return '%';
    if(check==6) return '^';
    if(check==7) return '~';
}

/* Does the arithmetic and returns the required result */
double do_arithmetic(double popped_first, double popped_last, int op_code)
{
   
    if(convert_int_to_op(op_code)=='+') return (popped_last + popped_first);
    /* -ve sign goes with the element popped first */
    if(convert_int_to_op(op_code)=='-') return (popped_last - popped_first);
    if(convert_int_to_op(op_code)=='*') return (popped_last * popped_first);
     /* The one popped first is the divisor */
    if(convert_int_to_op(op_code)=='/') return (popped_last / popped_first);
    if(convert_int_to_op(op_code)=='%') 
    {
        int popped_first_int=(int)popped_first;
        int popped_last_int=(int)popped_last;
        int eval= (popped_last_int % popped_first_int);
        return eval;
    }
    if(convert_int_to_op(op_code)=='^') 
    {
        int popped_first_int=(int)popped_first;
        int popped_last_int=(int)popped_last;
        int eval =power(popped_last_int, popped_first_int);        
        return eval;
    }
    return 0;
}

// Applies the tilde operator
double unary_minus(double x)
{
    return (0-x);
}

//This function prints the character array
void print_char_array(char a[], int length)
{
    for(int i=0; i<length; i++)
    {
        printf("%c",a[i]);
    }
    printf("\n");
}

/* Scans the character array and returns its length */
int scan_char_array(char a[])
{
    int i=0, temp;
    /* See the versatile use of getchar */
    temp=getchar();
    while(temp!='\n' && temp!='\0' && temp!=EOF)
    {
        a[i]=temp;
        i++;
        temp=getchar();
    }
    return i;
}


//Return 1 if the input is an operator
int is_operator(char check)
{
    int a= check=='+' || check=='-' || check=='*' || check=='/';
    int b= check=='%' || check=='^' || check=='~';
    return a||b;
}

// Parses the integer, given the starting point, and returns the new number along with the new index
struct Pair parse_int(char a[], int start, int length)
{
    Stack<int> stack;
    stack.top=-1;
    int i=start;
    int val, ans=0;
    struct Pair pair;
    /* As long as it is an integer, keep pushing it on the stack */
    while(i<length && (a[i]>='0' && a[i]<='9'))
    {
        val=a[i]-'0';
        stack.push(val);
        i++;
    }
    pair.second=i;
    int x=0;
    while(!stack.isEmpty())
    {
        val=stack.pop();
        ans = ans + val*power(10,x);
        x++;
    }
    pair.first=ans;
    return pair;
}

// Fills the token and returns its length
int fill_token(char a[], int length, struct Token token[])
{
    int t_index=0;
    int i=0;
    while(i<length)
    {
        /* Notice that if a space is encountered, the program will skip it */
        if(is_operator(a[i])) 
        {
            int op_code=convert_op_to_int(a[i]);
            token[t_index].tk_type=op_code;
            token[t_index].tk_val=op_code;
            t_index++;
            i++;
        }
        else if (a[i]>='0' && a[i]<='9')
        {
            struct Pair pair=parse_int(a,i,length);
            token[t_index].tk_type=0;
            token[t_index].tk_val=pair.first;
            t_index++;
            i=pair.second;
        }
        else i++;
    }
    return t_index;
}

// Prints the token
void print_token(struct Token token[], int length)
{
    for(int i=0; i<length; i++)
    {
        printf("%d %d\n",token[i].tk_type,token[i].tk_val);
    }
}

/* Returns the result, rounded off to the nearest integer */
int postfix_evaluation(struct Token token[], int token_length)
{
    int i=0;
    Stack<double> stack;
    stack.top=-1;
    while(i<token_length)
    {
        /* If it is a number */
        if(token[i].tk_type==0)
        {
            stack.push(token[i].tk_val);
            i++;
        }
        /* Handle unary minus */
        else if(token[i].tk_type==7)
        {
            double answer;
            double popped_first=stack.pop();
            answer=unary_minus(popped_first);
            stack.push(answer);
            i++;
        }
        else 
        {
            double answer;
            /* Notice the sequence */
            double popped_first=stack.pop();
            double popped_last=stack.pop();
            answer=do_arithmetic(popped_first, popped_last ,token[i].tk_type);
            stack.push(answer);
            i++;
        }
    }
    double temp=stack.pop();
    int answer=(int)temp;
    return answer;
}
int main() {
    
    char a[max_string_size];
    int t;
    scanf("%d",&t);
    char waste;
    scanf("%c",&waste);
    for(int i=0; i<t; i++)
    {
        int length;
        length=scan_char_array(a);
        struct Token token[max_token_size];
        int token_length= fill_token(a,length,token);
        int answer=postfix_evaluation(token,token_length);
        printf("%d\n",answer);
    }
    return 0;
}









