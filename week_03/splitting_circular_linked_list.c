// Program for  splitting a circular linked list into two halves 


#include<stdio.h>
#include<stdlib.h>

struct Node
{
int data;
struct Node *next;
};


void split_CL(struct Node *head, struct Node **head1,struct Node **head2)
{
struct Node *slow_ptr = head;
struct Node *fast_ptr = head;

if(head == NULL)
	return;

while(fast_ptr->next != head &&
		fast_ptr->next->next != head)
{
	fast_ptr = fast_ptr->next->next;
	slow_ptr = slow_ptr->next;
}

if(fast_ptr->next->next == head)
	fast_ptr = fast_ptr->next;	
*head1 = head;
if(head->next != head)
	*head2 = slow_ptr->next;
fast_ptr->next = slow_ptr->next;
slow_ptr->next = head;	
}



void insert(struct Node **head_ref, int data)
{
struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node));
struct Node *temp = *head_ref;
ptr1->data = data;
ptr1->next = *head_ref;
if(*head_ref != NULL)
{
	while(temp->next != *head_ref)
	temp = temp->next;	
	temp->next = ptr1;
}
else
	ptr1->next = ptr1; /*For the first node */

*head_ref = ptr1;	
}



void print_CL(struct Node *head)
{
struct Node *temp = head;
if(head != NULL)
{
	printf("\n");
	do {
	printf("%d ", temp->data);
	temp = temp->next;
	} while(temp != head);
}
}


int main()
{
int list_size, i;
struct Node *head = NULL;
struct Node *head1 = NULL;
struct Node *head2 = NULL;
insert(&head, 10);
insert(&head, 20);
insert(&head, 30);
insert(&head, 40);
insert(&head, 50);
insert(&head, 60);
insert(&head, 70);

printf("Original Circular Linked List");
print_CL(head);	

/* Split the list */
split_CL(head, &head1, &head2);

printf("\nFirst half Circular Linked List");
print_CL(head1);

printf("\nSecond half Circular Linked List");
print_CL(head2);

getchar();
return 0;
}

