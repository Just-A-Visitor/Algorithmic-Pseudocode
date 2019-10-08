/* Check your results here */

/*https://www.diffchecker.com */




#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* Change it to the number of test cases you want */
#define noOfTestCases 1

/* Change it to the number of queries you want in a single test case */
/* Don't go beyond 600*/
#define noOfQueries 400

/* Change it to the number of initial insertions you want */
#define initialInsertion 100

/* If you set this to 0, then same test case will be generated on each execution */
#define generateDifferentTestCases 1

/* Set the range of numbers */
#define start -10000
#define end 10000

/* See the function randomChoice to set frequency of choice, i.e, 
   if you want to generate test cases with only specific operations */

/* Returns a random int between the specified ranges */
int randomLowField()
{
    return rand()%(end-start+1) + start;
}

/* Returns the random high field of the interval, given the low one */
int randomHighField(int low)
{
    return abs(rand()%(end-start+1) + start) + low;
}

struct Interval
{
    int low;
    int high;
};

/* Function to assign different weights to choices */
/* Gives maximum weight to delete */
int randomChoice ()
{
    /* Modify this to vary the weight of choices */
    int choiceWeight[] = { 1,1,2,2,3,4,5,6,7};
    int numChoices = sizeof(choiceWeight)/sizeof(choiceWeight[0]);
    int sumOfWeights = 0;
    for(int i=0; i<numChoices; i++)
        sumOfWeights += choiceWeight[i];
    
    int rnd = rand()%(sumOfWeights+1);
    for(int i=0; i<numChoices; i++)
    {
        if(rnd <= choiceWeight[i]) return choiceWeight[i];
        rnd -= choiceWeight[i];
    }
}


void generateTestCase()
{
    
    Interval interval[100000];
    int index = 0, choice;
    int fromExisting;
    int low, high;
    
    /* Generate one of the 7 choices randomly */
    choice = randomChoice();
    printf("%d\n",noOfQueries );
    
    for(int i=0; i<initialInsertion; i++)
    {
            low = randomLowField();
            high = randomHighField(low);
           printf("+ %d %d\n",low,high);
           interval[index].low = low;
           interval[index++].high = high;
    }
    
    
    for(int i=0; i<(noOfQueries-initialInsertion); i++)
    {
 
        // First choice, add interval
        if(choice == 1)
        {
            low = randomLowField();
            high = randomHighField(low);
            printf("+ %d %d\n",low,high);
            interval[index].low = low;
            interval[index++].high = high;
           
        }
       
        // Second choice, delete interval
        else if(choice == 2)
        {
            // Randomly decide whether you need to delete the existing interval or garbage interval
            fromExisting = rand()%2 + 1;
            // Comment this to delete intervals not present in the tree
            fromExisting = 1;
            if(fromExisting == 1)
            {
                if(index==0)
                {
                    low = randomLowField();
                    high = randomHighField(low);
                    printf("- %d %d\n",low,high);
                }
                else
                {
                    int randomIndex = abs(rand()%index);
                    printf("- %d %d\n",interval[randomIndex].low, interval[randomIndex].high);
                    
                    /* Comment this part if you want to delete elements outside the set also */
                    interval[randomIndex] = interval[index-1];
                    index = index -1;
                    
                    /* Comment this part if you want to delete elements outside the set also */
                }
            }
           
           
            // uncomment to delete intervals not present in the tree
            /*
            else
            {
                low = rand()%(end-start+1) + start;
                high = abs(rand()%(end-start+1) + start) + low;
                printf("- %d %d ",low,high);
    
            }
            */
        }
       
        // Third choice, minimum interval
        else if(choice == 3) printf("min\n");
        // Fourth choice, maximum interval
        else if(choice == 4) printf("max\n");
       
        // Fifth choice , lsucc
        else if(choice ==5 )
        {
            // If there is no element in the tree, return the lsucc of random element, NULL.
            if(index == 0)
            {
                low = randomLowField();
                high = randomHighField(low);
                printf("lsucc %d %d\n",low,high);
    
            }
            // Return the lsucc of element in the tree
            else
            {
                int randomIndex = abs(rand()%index);
                printf("lsucc %d %d\n",interval[randomIndex].low, interval[randomIndex].high);
            }
           
        }
       
        // Sixth choice , hsucc
        else if(choice == 6 )
        {
            // If there is no element in the tree, return the lsucc of random element, NULL.
            if(index == 0)
            {
                low = randomLowField();
                high = randomHighField(low);
                printf("hsucc %d %d\n",low,high);
            }
            // Return the lsucc of element in the tree
            else
            {
                int randomIndex = abs(rand()%index);
                printf("hsucc %d %d\n",interval[randomIndex].low, interval[randomIndex].high);
            }

        }
       
        // Seventh choice: overlap
        else if(choice == 7 )
        {
            low = randomLowField();
            high = randomHighField(low);
            printf("overlap %d %d\n",low,high);
        }
       
        choice = randomChoice();
            
    }
    
   
}
int main() {
    
     /* Initialise time seed to generate different random number each time */
    if(generateDifferentTestCases) srand (time(NULL));
    
    printf("%d\n",noOfTestCases);
    for(int i=0; i<noOfTestCases; i++)
        generateTestCase();
    return 0;
}








