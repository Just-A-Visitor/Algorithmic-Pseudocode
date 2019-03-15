#include <stdio.h>
#include <iostream>
using namespace std;
/* Check for the size limits at the end, if error persists */ 
# define stack_size 100000
# define max_string_size 100000
# define max_token_size 100000

class Stack
{
    //set the access to public to allow smooth access to everybody
    public:
    
    //The stack class contains 2 members, an integer array, and an integer top
    int arr[stack_size];
    int top;
    
    //This member function pushes the key onto the stack, by first advancing the top pointer
    void push(int key)
    {
        top++;
        arr[top]=key;
    }
    
    //Pops the top element by decreasing the pointer first and then returning the previous element
    int pop()
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
    int peek()
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

// Returns the precedence order
int priority(int check)
{
    // In order +-*/%^~ 
    if(check==1 || check==2) return 1;
    if(check==3) return 2;
    if(check==4 || check==5) return 3;
    if(check==6) return 4;
    if(check==9) return 5;
    else return 0;
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
    if(check=='(') return 7;
    if(check==')') return 8;
    if(check=='~') return 9;
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
    if(check==7) return '(';
    if(check==8) return ')';
    if(check==9) return '~';
}

/* This function scans the string and returns its length */
/* Only the characters visible in string are included in length, not the null characters */
/* This function ignores the spaces while scanning */
struct Pair scan_char_array(char a[])
{
    int i=0; 
    int temp;
    /* Create auxillary array */
    char aux[max_string_size];
    int j=0;
    /* See the versatile use of getchar */
    temp=getchar();
    while(temp!='\n' && temp!='\0' && temp!=EOF)
    {
        aux[j]=temp; j++;
        if(temp!=' ') 
        {
            a[i]=temp;
            i++;
        }
        temp=getchar();
    }
    int aux_length=j, flag=0;
    //print_char_array(aux,aux_length);
    for(int k=1; k<(aux_length-1); k++)
    {
        
        if(aux[k]==' ')
        {
                if((aux[k-1]>='0' && aux[k-1]<='9') && (aux[k+1]>='0' && aux[k+1]<='9'))
                flag=1;
                
         }
    }
    //printf("%d\n",flag);
    struct Pair pair;
    pair.first=i;
    pair.second=flag;
    return pair;
}
//Returns a to the power b
int pow(int a, int b)
{
    int power=1;
    for(int i=0; i<b; i++)
    {
        power=power*a;
    }
    return power;
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

//Returns 1 if the input is illegal
int is_illegal(char check)
{
    if(convert_op_to_int(check)==0)
    {
        if(check>='0' && check <='9') return 0;
        else return 1;
    }
    return 0;
    /* Because, if op_to_int is not zero, it means it is an operator, therefore legal */
}

// Returns 0 if the expression is illegal
int is_valid_expression(char a[], int length)
{
    Stack stack;
    stack.top=-1;
    int waste;
    /* Check if the characters are legal and whether the parenthesis is balanced */ 
    for(int i=0; i<length; i++)
    {
        if(is_illegal(a[i])) return 0;
        if(a[i]=='(')
        {
            stack.push(1);
        }
        else if (a[i]==')')
        {
            if(stack.isEmpty()) return 0;
            waste=stack.pop();
        }
    }
    if(!stack.isEmpty()) return 0;
    /* So now, we only have operators and operand */ 
    
    /* Filling the array with operator codes of elements */
    int op_code[length];
    for(int i=0; i<length; i++)
    {
        op_code[i]=convert_op_to_int(a[i]);
    }
    
    /* Check the first element, The first element is a digit(0) or opening bracket(7) */
    if(op_code[0]==0 || op_code[0]==7);
    else return 0;
    /* Check the last element, It can either be a digit(0) or closing bracket(8) */
    if(op_code[length-1]==0 || op_code[length-1]==8);
    else return 0;
    
    int op_cur,op_next;
    for(int i=0; i<(length-1); i++)
    {
        op_cur=op_code[i];
        op_next=op_code[i+1];
            
        /* If it is a digit, the next element can be digit, operator or closing bracket */
        /* In short, it can be anything except ( */
        if(op_cur==0)
        {
            if(op_next==7) return 0;
        }
        /* If it is an opeator/opening bracket, the next can be a number or opening bracket only */
        /* In short, if you don't see 0, or a 7, return false */
        if(op_cur>=1 && op_cur<=7)
        {
            if(op_next==0 || op_next==7);
            else return 0;
        }
        /* Closing bracket:- The next can be operator or closing bracket*/
        /* In short, if you see digit or opening bracket, return false */
        if(op_cur==8)
        {
            if(op_next==0 || op_next==7) return 0;
        }
    }
    return 1;
}

//Return 1 if the input is an operator
int is_operator(char check)
{
    int a= check=='+' || check=='-' || check=='*' || check=='/';
    int b= check=='%' || check=='^' || check=='(' || check==')';
    return a||b;
}

// Parses the integer, given the starting point, and returns the new number along with the new index
struct Pair parse_int(char a[], int start, int length)
{
    Stack stack;
    stack.top=-1;
    int i=start;
    int val, ans=0;
    struct Pair pair;
    /* No whitespaces or illegal character */
    while(i<length && !is_operator(a[i]) && a[i]!='~')
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
        ans = ans + val*pow(10,x);
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
        if(is_operator(a[i]) || a[i]=='~') 
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
            i++;
            i=pair.second;
        }
    }
    return t_index;
}

void print_token(struct Token token[], int length)
{
    for(int i=0; i<length; i++)
    {
        printf("%d %d\n",token[i].tk_type,token[i].tk_val);
    }
}

// Prints the postfix notation
void post_fix(struct Token token[], int token_length)
{
    Stack stack;
    stack.top=-1;
    int temp;
    for(int i=0; i<token_length; i++)
    {
        int type=token[i].tk_type;
        int val=token[i].tk_val;
        
        /* If the token is integer, print and proceed */
        if(type==0)
        {
            printf("%d ",val);
            continue;
        }
        
        /* If token is '(', push it on the stack */
        else if(type==7) stack.push(type);
        
        /* If the token is ')', pop and print till you get first ). Don't print that, just pop it. */
        else if(type==8)
        {
            while(stack.peek()!=7)
            {
                temp=stack.pop();
                printf("%c ",convert_int_to_op(temp));
            }
            temp=stack.pop();
            continue;
        }
        
        /* If the token is an operator or unary */
        else if(type>=1 && type<=6 || type==9)
        {
            /* Check if the stack is empty or it contains '(' on top */
            if(stack.isEmpty() || stack.peek()==7)
            {
                stack.push(type);
                continue;
            }
            
            /* If it comes here, it means the stack is not empty and peek!='(' */
            /* Priority of the top is more, keep printing it till '(' */
            /* Note:-- As soon as stack becomes empty or '(', it pushes the op and proceeds */
            int flag=1;
            while (flag && priority(stack.peek())> priority(type))
            {
                temp=stack.pop();
                printf("%c ",convert_int_to_op(temp));
                if(stack.isEmpty() || stack.peek()==7)
                {
                    flag=0;
                    stack.push(type);
                    break;
                }
            }
            
            /* If it has come here, it means that element is already pushed */
            if(flag==0)
            {
                continue;
            }
            
            /* If they have same priority and the operator is left associative, i.e, not '^', op code 6, then pop it */
            if(!stack.isEmpty() && priority(stack.peek())==priority(type) && type!=6)
            {
                temp=stack.pop();
                printf("%c ",convert_int_to_op(temp));
                stack.push(type);
                continue;
            }
            
            /* If the operator is '6',  right associative, push it and continue */
            else if(!stack.isEmpty() && priority(stack.peek())==priority(type) && type==6)
            {
                stack.push(type);
                continue;
            }
            /* If the peeked element has less priority, push the current element */
            else if((!stack.isEmpty() && priority(stack.peek())<priority(type)))
            {
                stack.push(type);
                continue;
            }
        }
    }
    while(!stack.isEmpty())
    {
        temp=stack.pop();
        printf("%c ",convert_int_to_op(temp));
    }
    printf("\n");
}
int main() {
    
    char a[max_string_size];
    int t;
    scanf("%d",&t);
    char waste;
    scanf("%c",&waste);
    for(int i=0; i<t; i++)
    {
        struct Pair pair;
        pair=scan_char_array(a);
        int length=pair.first;
        int is_digits_cons=pair.second;
        if(is_digits_cons==1) 
        {
            printf("INVALID\n");
            continue;
        }
        
        /* Creates a copy */
        char copy[length];
        for(int i=0; i<length; i++)
        {
            copy[i]=a[i];
        }

        /* Replace unary minus with tilde */
        /* Check if the first needs to be converted */
        if(a[0]=='-')
        {
            /* If the length is one, do nothing */
            /* If the next character is '(' or digit, replace it by tilde */
            if(length==1);
            else if(a[1]=='(' || (a[1]>='0' && a[1]<='9'))
            {
                copy[0]='~';
            }
        }
        
        /* This loop checks all except the first and last elements whether they are candidates for tilde */
        for(int i=1; i<(length-1); i++)
        {
            if(a[i]=='-')
            {
                /* If The previous chracter is an operator, and also not the ')' operator */
                if(is_operator(a[i-1]) && a[i-1]!=')')
                {
                    /* If the next character is a digit or '(', make it tilde */
                    if((a[i+1]>='0' && a[i+1]<='9') || a[i+1]=='(')
                    copy[i]='~';
                }
            }
        }
        /* The last element cannot be a candidate for tilde */
        
        /* Ignore the tilde */
        char final_copy[length];
        int index=0;
        for(int i=0; i<length; i++)
        {
            if(copy[i]!='~')
            {
                final_copy[index]=copy[i];
                index++;
            }
        }
        int final_length=index;
        
        int check=is_valid_expression(final_copy,final_length);
        if(check==0)
        {
            printf("INVALID\n");
        }
        else 
        {
            struct Token token[max_token_size];
            int token_length= fill_token(copy,length,token);
            int operand_count=0, operator_count=0;
            for(int i=0; i<token_length; i++)
            {
                if(token[i].tk_type==0) operand_count++;
                if(token[i].tk_type>=1 && token[i].tk_type<=6) operator_count++;
            }
            if(operand_count-operator_count!=1) 
            {
                printf("INVALID\n");
                continue;
            }
            post_fix(token,token_length);
            
        } 
    }
    return 0;
}







