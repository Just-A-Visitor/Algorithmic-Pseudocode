/* An amazing thing about Javascript. Semi-Colons are optional :) */


console.log("Hello from JavaScript");

var number = 5;  // This is an inline comment

/* This is a multiline comment.
   It extends to multiple lines */

number = 9;


/* Data Types in JavaScript */
/* undefined, null, boolean, string, symbol, number and object  */


/* Declaring a variable */
/* A variable can be set to anything */
var myName = "Masood";

/* Types can be easily interchanged*/
/* Amazing */

myName = 8;


/* Alternate way of declaring a variable */
let myNewName = 10;

/* The last way to declare a variable */
const pi = 3.14;

/* Difference between the 3 types of declaration */

/*
1) var can be used throughout the program, while let has local scope
2) const can never change
*/

/* Declaring and assigning variables */
var a;
var b=2;

// Priting things to a console
// Notice that a is null
console.log(a);
console.log(b);

a=7;
b=a;

// Printing things to a console
console.log(a);

// String concatenation works
var myString = "Hi, I am a ";
myString = myString + "new string";
console.log(myString);


/* Of course, it is case sensitive like C++ */

// Let use see the type of divison
number = 5;
number = number/2;
console.log(number);

// As we can see,it behaves like python, (No Floor divison)


/* Using double quotes inside a string by escaping via \*/
myString = "I am a \"double quote\" string";
console.log(myString);

/* An alternative way to do this by using single quotes for initialisation*/

myString = 'I am a "double quotes" string';
console.log(myString);


/* What happens if you want to use single and double quotes inside? Use Backticks */
myString = `I am 'a' "double quotes" string`;
console.log(myString);


/* Cheat Sheet for escaping character in a string*/
/*
 *  \' single quote
 *  \" double quotes
 *  \n newLine
 *  \\ backslash
 *  \t tab
 */


/* Concatenating strings with variables */
var newString = "Masood";
var checkIt = "Hello " + newString + " How are you";
console.log(checkIt);


/* Finding the length of a string */
/* length is like an attribute */
var stringLength = checkIt.length;
console.log(stringLength);

/* Bracket notation works like C++*/
console.log(checkIt[0]);


/* Strings are immutable. They can be concatenated but the literals cannot change */
//checkIt[1] = 'z';


/* Defining function is simple. Just write function */
function newFunction(firstArgument, secondArgument)
{
    return "Successfully executed";
}

console.log(newFunction(1,2));



/*
 * Working with arrays
 */

// You can use a mixture of data types
var newArray = [];
newArray = ["Hi", 2];
console.log(newArray);

/* Working with 2d Arrays. Exactly like python */
var matrix = [['Hi', 'It\'s'],['me', 'here']];
console.log(matrix);

/* Bracket Notation works. Arrays are mutable */
/* Index chaining works exactly like C++ */


/* Appending an element at the end of the array? Use push */
var myArray = ['hi', 'There'];
myArray.push(['How','are', 'you']);
console.log(myArray);

/* Pop also works. By OOPS, you can either catch or ignore it*/
var poppedValue = myArray.pop();
console.log(myArray);
console.log(poppedValue);
poppedValue.pop();
console.log(poppedValue);


/* Removing an element from the front ? Use shift method */
/* Value can be ignored */

var firstElement = myArray.shift();
console.log(myArray);

/* Adding an element to the front ? Use unshift method */
myArray.unshift('Hi');
console.log(myArray);


/* The typeof operator */
console.log(typeof myArray);

// Data type of undefined variable
console.log(typeof amIEvenDefined);



/* A very important point */
/* If you declare something inside a function without using var,
   it becomes global automatically */

function letUsCheck()
{
    var iWasNotDefined = 10;
}


letUsCheck();
//console.log(iWasNotDefined);

/* This won't happen in Scrimba, but it would happen in browser */


/* Local variable overshadows global variables */
var globalVariable = 10;

function testFunction()
{
    var globalVariable = 20;
    console.log(globalVariable);
}

testFunction();
console.log(globalVariable);


/* Converting an array to a string */
/* Use JSON.stringify */

myArray = [11,22,43,47];
var newString = JSON.stringify(myArray);
console.log(typeof newString);
console.log(newString);
console.log(newString[0]);
console.log(newString[3]);

// As you can see, it even stringifies the [] and ,

/* How do you implement a queue? Use shift method */

/* New concept */
/* The == performs a type conversion first */
/* The triple equals (The strict equality )*/

console.log(3=='3');
// The above code evaluates to true because JS parses them to same format

// To check strict equality, use ====
console.log(3==='3');

// Strict inequality operator !==
console.log(3!=='3');
