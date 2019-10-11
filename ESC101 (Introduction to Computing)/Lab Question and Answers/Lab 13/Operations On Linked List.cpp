#include<stdio.h>
#include<stdlib.h>

struct node_t{
    int val;
    struct node_t* next;
};

typedef struct node_t node;

void insert(node* head, int val)
{	
    	node* new_node;
	new_node=(node*)malloc(sizeof(node));
	new_node->val=val;
	node* curr=head;
	while(curr->next!=NULL)
	{
		curr=curr->next;
	}
	curr->next=new_node;
	new_node->next=NULL;
	// Write code to insert an element at the end of the linked list with given head
}

node* delete(node* head, int val)
{
    	node* curr=head;
	if(head->val==val)
	{
		node* temp=head->next;
		free(head);
		return temp;	
	}
	while(curr->next!=NULL)
	{
		if((curr->next)->val==val) break;
		curr=curr->next;
	}
	if(curr->next==NULL) return head;
	node* temp;
	temp=(curr->next)->next;
	free(curr->next);
	curr->next=temp;
	return head;
	
	// Write code to delete an element with value val from the linked list with given head
    	// Return the head (Hint: If the head itself is deleted, then return new head)
}

void print_list(node* head)
{	
    	node* curr=head;
	while(curr->next!=NULL)
	{
		printf("%d ",curr->val);
		curr=curr->next;
	}
	printf("%d\n",curr->val);
	return;
	// Print the contents of the linked list starting from head    
}

int main(){
    node* head;
    head = (node*)malloc(sizeof(node));
    head->val = 100;
    head->next = NULL;
    
    insert(head,10);
    insert(head,92);
    print_list(head);
    insert(head,34);
    head = delete(head,15);
    head = delete(head,100);
    head = delete(head,34);
    print_list(head);
    
    if (head)
        free(head);
        // Freeing is necessary!
        
    return 0;
}
