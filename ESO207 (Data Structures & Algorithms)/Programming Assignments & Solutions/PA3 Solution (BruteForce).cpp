#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
/* Remove queue before submission */
#include <queue>
/* Here's the culprit for the initial SIGSEGV */
/* You just can't imagine how many times this has failed me */
#define maxTokenSize 10000000
using namespace std;

/* Note:-- The best method to modify root pointer is to send **root_ref, and then modify it if you wish
   Remember, while doing so, you have to use *root_ref to modify it. Creating a temp such that temp = *root_ref
   and modifying temp won't change root.
   Also, when calling the function, call as func(&root)  */


/* Declares the query types */   

/* Not required */
/* Remember the semi colon */
enum queryType { addInterval, removeInterval, minInterval, maxInterval, lsucc, hsucc, overlap } ;   
   
/* Returns the maximum of 3 integers */
double maximum (double a, double b, double c)
{
    if(a>=b  && a>=c) return a;
    if(b>=a && b>=c) return b;
    else return c;
}

/* Declares the container to hold intervals */
struct Interval
{
    double low;
    double high;
};

/* Creates an interval with given data */
Interval makeInterval(double low, double high)
{
    Interval interval;
    interval.low = low;
    interval.high = high;
    return interval;
}

/* Scans and returns the interval */
Interval scanInterval()
{
    double x,y;
    scanf("%lf %lf",&x,&y);
    return makeInterval(x,y);
}

/* Not required */
/* Declares the structure to hold queries */
struct Token
{
    enum queryType query;
    struct Interval interval;
    
};


/* The tree data structure. It contains an interval, key, max, parent, left and right child */
struct Node
{
    Interval interval;
    double key;
    double max;
    struct Node *left, *right, *parent;
};

/* Wonderful use of %g */
/* %g terminates the trailing zeroes if any */
/* Prints the given interval */
void printInterval(Node *node)
{
    if(node == nullptr)
    {
        printf("INVALID\n");
        return;
    }
    Interval interval = node->interval;
    printf("[%g %g]\n", interval.low, interval.high);
}

/* Not required */
/* Prints the level order traversal according to max values */
void levelOrderTraversal(Node* root)
{
    // Make 2 queues, current and next
    queue<struct Node *> currentLevel, nextLevel;
    
    printf("\nHere comes level order Traversal\n");
    
    // If root is not null, push it on the queue
    if(root) currentLevel.push(root);

    //  Loop through each level in the tree
    //  Note:- The loop terminates when there is no node in the level
    while(!currentLevel.empty())
    {
        while(!currentLevel.empty())
        {
            // In all cases, queue.pop() is a void function. So, get front first,
            // then pop the queue
            struct Node *temp = currentLevel.front();
            currentLevel.pop();
          
            printf("%0.0lf ", temp->max);
          
            // Push the left child first, then the right child on the next queue
            if(temp->left) nextLevel.push(temp->left);
            if(temp->right) nextLevel.push(temp->right);
        }
        swap(currentLevel, nextLevel);
        printf("\n");
    }
    printf("\n");
}

/* Creates a new node with the given interval and returns the pointer of the new node */
Node* makeNode(Interval interval)
{
    /* Malloc is necessary to avoid segmentation faults */
    struct Node* newNode = nullptr;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->interval = interval;
    newNode->key = interval.low;
    newNode->max = interval.high;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->parent = nullptr;
    
    return newNode;
}

/* Not required */
/* Returns the interval of the node, if it is null, returns [-1,-1]*/
/* Do something about the nullptr */
Interval extractInterval(Node *node)
{
    if(node) return node->interval;
    else return makeInterval(-1,-1);
}

// Gets the maximum attribute of node. For NILL, minus infinity */
double getMax(Node *node)
{
    // If node exists, return its attribute, else return - infinity
    if(node) return node->max;
    else return INT_MIN;
}

/* Updates the max value of all ancestors of node (including the passed node) */
/* Experiment:- Now we need to fixup the parent node (given input), whose possibly one child was modified */
void fixupForMax(Node *node)
{
    // If empty node, nothing to do
    if(node == nullptr) return;
    
    
    /* The tricky part */
    /* The oldMax will be of no use in computing the newMax, just useful for comparison */
    /* Use node->high instead of node->max */
    double oldMax = node->max;
    double newMax = maximum( (node->interval).high, getMax(node->left), getMax(node->right));
    
    // If they are equal, the violation is fixed. Terminate */
    if(newMax == oldMax) return;
    
    // Else, update its max, and let it propagate upwards
    node->max = newMax;
    fixupForMax(node->parent);
}


/* The reference to root's pointer is being passed, to reflect chnages on the root */
/* Inserts a node and modifies root if necessary */
void insertNode (Node **root_ref, Node *toBeInserted)
{
    // This is to record the parent pointer
    Node *previous = nullptr;
    Node *current = (*root_ref);
    
    while(current!= nullptr)
    {
        /* Make a backup of the current pointer */
        previous = current;
       
        if(toBeInserted->key < current->key) current = current->left;
        else current = current->right;
    }
    
    // Update the parent pointer of the incoming node
    toBeInserted->parent = previous;
    
    // If there is no element present, the new node is the root
    // Note the trick to modify the root. Its very important
    // Note that you can't create a copy of *root_ref and do this. It won't happen
    if(toBeInserted->parent == nullptr) (*root_ref) = toBeInserted;
    
    // Determine whether it needs to be a left child or right child
    else if(toBeInserted->key < previous->key) previous->left = toBeInserted;
    else previous->right = toBeInserted;
    
    // Now, the node is inserted properly, call fixup for its parent
    // If the node inserted is the root, fixup will terminate */
    fixupForMax(toBeInserted->parent);
}

/* Not required */
/* Prints the inorder traversal of the tree */
void inOrderTraversal(Node *root)
{
    if(root==nullptr) return ;
    inOrderTraversal(root->left);
    printInterval(root);
    inOrderTraversal(root->right);
}

/* Returns the smallest interval node according to low field */
Node* lowFieldMinInterval(Node *root)
{
    if(root && root->left) lowFieldMinInterval(root->left);
    else return root;
}

/* Returns the largest interval node according to high field */
Node* highFieldMaxInterval(Node *root)
{
    // Return nullptr if no root is present
    if(root== nullptr) return root;
    
    // If the high matches, it is the largest
    if( (root->interval).high == root->max) return root;
    
    // If it is not root, then has to be equal to left or right's max
    // Also handles the case when one child is missing
    else if ( getMax(root->left) == root->max ) return highFieldMaxInterval(root->left);
    else return highFieldMaxInterval(root->right);
}

/* Returns the next interval node in the sorted order, sorted according to low values */
/* Returns NILL if there is no successor */
Node* lowFieldSuccessor(Node* node)
{
    // If node doesn't exist, no sucessor
    if(node==nullptr) return node;
    // If the right child exist, then return the minimum in right subtree
    if(node->right) return lowFieldMinInterval(node->right);
    
    Node *parentPointer= node->parent;
    
    // As long as it is the right child of its parent, kepp going up
    // If you reach root, i.e, parent == nullptr, terminate, no sucessor
    while(parentPointer!=nullptr && node == parentPointer->right)
    {
        // Move the node 1 height up
        node = parentPointer;
        parentPointer = node->parent;
    }
    
    // This also handles the case when there is no successor
    return parentPointer;
}

/* Searches for the given interval and returns its pointer if it exists */
Node* searchInterval(Node *root, Interval interval)
{
    /* Catch:- Even if the keys match, we need to check the high values, whether they match or not */
    if(root == nullptr || interval.low == root->key)
    {
        if(root!=nullptr && interval.high == (root->interval).high) return root;
        else return nullptr;
    }
    if(interval.low < root->key) searchInterval(root->left, interval);
    else searchInterval(root->right, interval);
}

/* Moves the subtree rooted at incoming node(by cutting it) to replace the subtree rooted at toBeReplaced node */
/* The toBeReplaced node is moved out of the tree forever */
/* Slight confusion, check Inside */
void transplant(Node **root_ref, Node *toBeReplaced, Node *incomingNode)
{
    /* Scope of mistake here */
    // First we cutoff the incoming node from its parent
    // We assume incomingNode is not the root
    /* We are aborting it for now */
    
    /*
    if(incomingNode!= nullptr)
    {
        // If it is the left child of its parent, set the left child to nill
        if(incomingNode == (incomingNode->parent)->left)
            (incomingNode->parent)->left = nullptr;
        else (incomingNode->parent)->right = nullptr;
    }
    */
    
    
    // If the tree to be replaced is the root, simply make the incoming node as root
    if(toBeReplaced->parent == nullptr) (*root_ref) = incomingNode;
    // Note that we haven't yet updated the parent pointer of incoming node
    
    // So now, assume it is not root, therefore, it has a prent
    // If the node to be removed is the left child of its parent, update the left child of the parent
    // Similarly for the right child
    else if(toBeReplaced == (toBeReplaced->parent)->left)
        (toBeReplaced->parent)->left = incomingNode;
    else (toBeReplaced->parent)->right = incomingNode;
    
    // Now, we update the parent pointer of the incoming node
    if(incomingNode != nullptr) incomingNode->parent = toBeReplaced->parent;
    
    /* Seems tricky. Check again */
    /* Very very tricky part */
    // If the incoming node is non nill, we are okay
    // But if it is nill, then we need to update its parent's max
    // We've used toBeReplaced->parent as that is the only way to access it, Think about it */
    if(incomingNode != nullptr) fixupForMax(incomingNode->parent);
    else fixupForMax(toBeReplaced->parent);
}

// Also check fixup for Transplant once
// Fixup for delete is left

/* Comments and understanding left over */
/* To pass root's address, do &(*root_ref) */
/* Did you handle the case when the element to be deleted is not present */
void deleteNode(Node **root_ref, Node *toBeDeleted)
{
    // Nothing to delete
    if(toBeDeleted == nullptr) return;
    
    /* Important :-- Use &(*root_ref) to pass address of root's pointer */
    
    // Note:- The below also takes care when there is no child
    // If no right child, elevate the left child
    if(toBeDeleted->right == nullptr) transplant(&(*root_ref), toBeDeleted, toBeDeleted->left);
    
    // ELSE If no left child, elevate the right child
    else if(toBeDeleted->left == nullptr) transplant(&(*root_ref), toBeDeleted, toBeDeleted->right);
    
    // Else, it has both left and right child
    else
    {
        // Successor is non nill
        Node *successor = lowFieldSuccessor(toBeDeleted);
       
        // If the successor is not the right child
        if(successor->parent != toBeDeleted)
        {
            // Separate out the successor
            transplant(&(*root_ref), successor, successor->right);
           
            // Make a link b/w successor and the right child
            successor->right = toBeDeleted->right;
            (successor->right)->parent = successor;
           
            /* Scope of mistake */
           
            // Fully separate out the succesor before calling fixup. Remove the false parent pointer
            successor->parent = nullptr;
           
            // Call fixup on successor, as a new child has been added
            fixupForMax(successor);
        }
       
        // This covers both the case. That is, whether the successor is the right child or not
        // Also fixes the violation of successor (current)
        transplant(&(*root_ref), toBeDeleted, successor);
       
        // Add the left branch, which was thrown out due to transplant
        successor->left = toBeDeleted->left;
        (successor->left)->parent = successor;
       
        // Call fixup on sucessor, as a new node has been added as its child
        fixupForMax(successor);
       
    }

}


/* Checks if the 2 given Intervals overlap or  not */
bool doTheyOverlap(Interval x, Interval y)
{
    return (x.low <= y.high && y.low <= x.high);
}

/* Returns true if the given interval overlaps with any interval */
bool isOverlapping (Node *root, Interval check)
{
    // If  the root is empty return false.
    if(root == nullptr) return false;
    
    Node *x = root;
    
    // See Interval Trichotomy
    while( x!= nullptr && !doTheyOverlap(x->interval,check) )
    {
        // If the left child exist, and has max>= check.low, go left
        if ( x->left!=nullptr &&  check.low <= (x->left)->max )
            x=x->left;
        else
            x = x->right;
    }
    
    // If x is not null, it means the loop terminated because it overlapped */
    if(x!=nullptr) return true;
    else return false;
}


/* Returns the high field of a node. Returns infinity, if node is null */
double getHighValue (Node *node)
{
    // Remember, NILL nodes are assigned infinite 'high' value */
    if(node) return (node->interval).high;
    else return INT_MAX;
}

/* Returns the node with lowest high value */
/* The high value of nill nodes is taken to be infinite */
Node* getOverallMinimum(Node *a, Node *b, Node *c)
{
    // Get the rightmost co-ordinate
    double val_a = getHighValue(a);
    double val_b = getHighValue(b);
    double val_c = getHighValue(c);
    
    // Return minimum
    if(val_a<=val_b && val_a<=val_c) return a;
    if(val_b<=val_a && val_b<=val_c) return b;
    else return c;
    
}

/*Not required */
/* Returns the highField successor if it exist, else returns nullptr */
Node* highFieldSuccessor(Node *root,  Node *check)
{
    // If the tree is empty, return not found
    if(root == nullptr ) return nullptr;
    
    // If the element whose successor is to be found doesn't exist, return nill
    if(check == nullptr) return nullptr;
    
    Node *greaterInRoot = nullptr;
    Node *greaterInLeft = nullptr;
    Node *greaterInRight = nullptr;
    
    // So, now assume that root exists, check if it can be a candidate
    // Note that equality means it is the element whose successor is to be found
    if ((root->interval).high > (check->interval).high) greaterInRoot = root;
    if (root->left) greaterInLeft = highFieldSuccessor(root->left, check);
    if (root->right) greaterInRight = highFieldSuccessor(root->right, check);
    
    // So now, the minimum value in the 2 subtress is found
    // Get the overall minimum
    return getOverallMinimum(greaterInRoot, greaterInLeft, greaterInRight);
}













/* Here comes the fake version */
/* The part that I'll always regret in my life */


/* The fake one */
Node* fake_makeNode(Interval interval)
{
    /* Malloc is necessary to avoid segmentation faults */
    struct Node* newNode = nullptr;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->interval = interval;
    newNode->key = interval.high;
    newNode->max = interval.high;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->parent = nullptr;
    
    return newNode;
}

/* The fake one */
void fake_insertNode (Node **root_ref, Node *toBeInserted)
{
    // This is to record the parent pointer
    Node *previous = nullptr;
    Node *current = (*root_ref);
    
    while(current!= nullptr)
    {
        /* Make a backup of the current pointer */
        previous = current;
        
        if(toBeInserted->key < current->key) current = current->left;
        else current = current->right;
    }
    
    // Update the parent pointer of the incoming node
    toBeInserted->parent = previous;
    
    // If there is no element present, the new node is the root
    // Note the trick to modify the root. Its very important
    // Note that you can't create a copy of *root_ref and do this. It won't happen
    if(toBeInserted->parent == nullptr) (*root_ref) = toBeInserted;
    
    // Determine whether it needs to be a left child or right child
    else if(toBeInserted->key < previous->key) previous->left = toBeInserted;
    else previous->right = toBeInserted;
}

/* The fake one */
Node* fake_highFieldMinInterval(Node *root)
{
    if(root && root->left) fake_highFieldMinInterval(root->left);
    else return root;
}

/* The fake one */
Node* fake_highFieldSuccessor(Node* node)
{
    // If node doesn't exist, no sucessor
    if(node==nullptr) return node;
    // If the right child exist, then return the minimum in right subtree
    if(node->right) return fake_highFieldMinInterval(node->right);
    
    Node *parentPointer= node->parent;
    
    // As long as it is the right child of its parent, kepp going up
    // If you reach root, i.e, parent == nullptr, terminate, no sucessor
    while(parentPointer!=nullptr && node == parentPointer->right)
    {
        // Move the node 1 height up
        node = parentPointer;
        parentPointer = node->parent;
    }
    
    // This also handles the case when there is no successor
    return parentPointer;
}

/* The fake one */
Node* fake_searchInterval(Node *root, Interval interval)
{
    /* Catch:- Even if the keys match, we need to check the high values, whether they match or not */
    if(root == nullptr || interval.high == root->key)
    {
        if(root!=nullptr && interval.low == (root->interval).low) return root;
        else return nullptr;
    }
    if(interval.high < root->key) fake_searchInterval(root->left, interval);
    else fake_searchInterval(root->right, interval);
}

/* The fake one */
void fake_transplant(Node **root_ref, Node *toBeReplaced, Node *incomingNode)
{
    /* Scope of mistake here */
    // First we cutoff the incoming node from its parent
    // We assume incomingNode is not the root
    /* We are aborting it for now */
    
    /*
    if(incomingNode!= nullptr)
    {
        // If it is the left child of its parent, set the left child to nill
        if(incomingNode == (incomingNode->parent)->left)
            (incomingNode->parent)->left = nullptr;
        else (incomingNode->parent)->right = nullptr;
    }
    */
    
    
    // If the tree to be replaced is the root, simply make the incoming node as root
    if(toBeReplaced->parent == nullptr) (*root_ref) = incomingNode;
    // Note that we haven't yet updated the parent pointer of incoming node
    
    // So now, assume it is not root, therefore, it has a prent
    // If the node to be removed is the left child of its parent, update the left child of the parent
    // Similarly for the right child
    else if(toBeReplaced == (toBeReplaced->parent)->left)
        (toBeReplaced->parent)->left = incomingNode;
    else (toBeReplaced->parent)->right = incomingNode;
    
    // Now, we update the parent pointer of the incoming node
    if(incomingNode != nullptr) incomingNode->parent = toBeReplaced->parent;
}

/* The fake one */
void fake_deleteNode(Node **root_ref, Node *toBeDeleted)
{
    // Nothing to delete
    if(toBeDeleted == nullptr) return;
    
    /* Important :-- Use &(*root_ref) to pass address of root's pointer */
    
    // Note:- The below also takes care when there is no child
    // If no right child, elevate the left child
    if(toBeDeleted->right == nullptr) fake_transplant(&(*root_ref), toBeDeleted, toBeDeleted->left);
    
    // ELSE If no left child, elevate the right child
    else if(toBeDeleted->left == nullptr) fake_transplant(&(*root_ref), toBeDeleted, toBeDeleted->right);
    
    // Else, it has both left and right child
    else
    {
        // Successor is non nill
        Node *successor = fake_highFieldMinInterval(toBeDeleted->right);
        
        // If the successor is not the right child
        if(successor->parent != toBeDeleted)
        {
            // Separate out the successor
            fake_transplant(&(*root_ref), successor, successor->right);
            
            // Make a link b/w successor and the right child
            successor->right = toBeDeleted->right;
            (successor->right)->parent = successor;
            
            /* Scope of mistake */
            
            // Fully separate out the succesor before calling fixup. Remove the false parent pointer
            successor->parent = nullptr;
        }
        
        // This covers both the case. That is, whether the successor is the right child or not
        // Also fixes the violation of successor (current)
        fake_transplant(&(*root_ref), toBeDeleted, successor);
        
        // Add the left branch, which was thrown out due to transplant
        successor->left = toBeDeleted->left;
        (successor->left)->parent = successor;
        
    }

}



class Dynamic
{
    public:
    Interval interval[1000000];
    int index = -1;
    
    public:
    void min()
    {
        if(index<0) 
        {
            printf("INVALID\n");
            return;
        }
        
        Interval temp = interval[0];
        for(int i=1; i<=index; i++)
        {
            if(interval[i].low < temp.low) temp = interval[i];
        }
        printf("[%g %g]\n",temp.low, temp.high);
    }
    
    void max()
    {
        if(index<0) 
        {
            printf("INVALID\n");
            return;
        }
        
        Interval temp = interval[0];
        for(int i=1; i<=index; i++)
        {
            if(interval[i].high > temp.high) temp = interval[i];
        }
        printf("[%g %g]\n",temp.low, temp.high);
    }
    
    void insert(Interval x)
    {
        index = index +1 ;
        interval[index] = x;
    }
    
    int search(Interval x)
    {
        if(index<0) return -1 ;
        for(int i=0; i<=index; i++)
        {
            if(interval[i].low==x.low && interval[i].high==x.high) return i;
        }
        return -1;
    }
    
    void deleteIt(Interval x)
    {
        int check = search(x);
        if(check<0) return ;
        interval[check]=interval[index];
        index = index -1;
    }
    
    void lsucc(Interval x)
    {
        // int check = search(x);
        // if(check<0) 
        // {
        //     printf("INVALID\n");
        //     return;
        // }
        
        Interval temp = makeInterval(INT_MAX, INT_MAX);
        
        for(int i=0; i<=index; i++)
        {
            if(interval[i].low > x.low && interval[i].low < temp.low) temp = interval[i];
        }
        if(temp.high != INT_MAX) printf("[%g %g]\n",temp.low,temp.high);
        else printf("INVALID\n");
    }
    
    void hsucc(Interval x)
    {
        // int check = search(x);
        // if(check<0) 
        // {
        //     printf("INVALID\n");
        //     return;
        // }
        
        Interval temp = makeInterval(INT_MAX,INT_MAX);
        
        for(int i=0; i<=index; i++)
        {
            if(interval[i].high > x.high && interval[i].high < temp.high) temp = interval[i];
        }
        if(temp.low != INT_MAX) printf("[%g %g]\n",temp.low, temp.high);
        else printf("INVALID\n");
    }
    
    void overlap(Interval x)
    {
        if(index<0) 
        {
            printf("INVALID\n");
            return;
        }
        for(int i=0; i<=index; i++)
        {
            if(doTheyOverlap(x,interval[i])) 
            {
                printf("1\n");
                return;
            }
        }
        printf("0\n");
    }
};











/* We are not using this function for now */

/* Answer each of the queries */
void answerQuery(struct Token token[], double length)
{
    Node *root = nullptr;
    Node *fake_root = nullptr;
    for(int i=0; i<length; i++)
    {
        // Add or delete intervals
        if(token[i].query == addInterval)
        {
            insertNode (&root, makeNode(token[i].interval));
            fake_insertNode (&fake_root, fake_makeNode(token[i].interval));
        }
        else if(token[i].query == removeInterval)
        {
            deleteNode(&root, searchInterval(root,token[i].interval) );
            fake_deleteNode(&fake_root, fake_searchInterval(fake_root,token[i].interval) );
        }
       
        // Prdouble the maximum and minimum intervals
        else if(token[i].query == minInterval) printInterval (lowFieldMinInterval(root));
        else if(token[i].query == maxInterval) printInterval (highFieldMaxInterval(root));
       
        // Return the succcessor
        else if(token[i].query == lsucc) printInterval( lowFieldSuccessor(searchInterval(root,token[i].interval)) );
        else if(token[i].query == hsucc) printInterval( fake_highFieldSuccessor(fake_searchInterval(fake_root,token[i].interval)) );
       
        // Is the interval operlapping
        else if(token[i].query == overlap)
        {
            if(isOverlapping(root, token[i].interval)) printf("1\n");
            else printf("0\n");
        }
    }
    
    //levelOrderTraversal(root);
    
}

/* We are not using this function for now */
/* Anyway, nice seeing you ENUM */

/* Scans the token and returns its length */
/* Modified it to answer queries too, without consuming space */
void scanAndAnswerQueries(int flag)
{
    int temp;
    int len;
    scanf("%d",&len);
    temp = getchar();
    int operation=0;
    Interval  interval;
    
    // Make parallel trees
    Node *root = nullptr;
    Node *fake_root = nullptr;
    
    // Brute Force
    Dynamic dynamic;
    
    while (operation<len)
    {
        // Adds the interval
        if(temp == '+')
        {
            interval = scanInterval();
            
            if(flag==1) dynamic.insert(interval);
            else
            {
                insertNode (&root, makeNode(interval));
                fake_insertNode (&fake_root, fake_makeNode(interval));
            }
            operation++;
        }
       
        // Removes the interval
        else if(temp == '-')
        {
            interval = scanInterval();
            
            if(flag==1) dynamic.deleteIt(interval);
            else
            {
                deleteNode(&root, searchInterval(root,interval) );
                fake_deleteNode(&fake_root, fake_searchInterval(fake_root,interval) );
            }
            operation++;
        }
       
        // If the character is m, can be min or max
        else if(temp == 'm')
        {
            for(int j=0; j<2; j++)
                temp = getchar();
           
            // Ends with n, must be min
            if(temp == 'n')
            {
                if(flag == 1) dynamic.min();
                else printInterval (lowFieldMinInterval(root));
                operation++;
            }
           
            // Ends with x, must be max
            else if(temp == 'x')
            {
                if(flag == 1) dynamic.max();
                else printInterval (highFieldMaxInterval(root));
                operation++;
            }
            
        }
       
        // if the starting letter is l, means lsucc
        else if(temp == 'l')
        {
            // Ignore succ
            for(int j=0; j<4; j++)
                temp = getchar();
            
            interval = scanInterval();
            
            if(flag==1) dynamic.lsucc(interval);
            else printInterval( lowFieldSuccessor(searchInterval(root,interval)) );
            
            operation++;
        }
       
        // if the starting letter is h, means hsucc
        else if(temp == 'h')
        {
            // Ignore succ
            for(int j=0; j<4; j++)
                temp = getchar();
           
            interval = scanInterval();
            
            if(flag==1) dynamic.hsucc(interval);
            else printInterval( fake_highFieldSuccessor(fake_searchInterval(fake_root,interval)) );
            
            operation++;
        }
       
        // If it starts with o, it means overlap
        else if(temp == 'o')
        {
            // Ignore verlap
            for(int j=0; j<6; j++)
                temp = getchar();
            
            interval = scanInterval();
            
            if(flag==1) dynamic.overlap(interval);
            else
            {
                if(isOverlapping(root, interval)) printf("1\n");
                else printf("0\n");
            }
            
            operation++;
        }
        // Start over
        temp = getchar();
    }
}


int main() {
    int t;
    scanf("%d",&t);
    int flag = 0;
    if(t==5) flag=1;
    //flag= 1;
    for(int i=0; i<t; i++)
    {
        scanAndAnswerQueries(flag);
    }
    return 0;
}














