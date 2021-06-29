// Given a linked list(singly - linked, non - circular), write a program to swap the kth node from beginning
// with the kth last node in the list. Note that the length of the list is not known.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void swap_kth_begin_last(struct Node *head, int n)		// Function to get the nth node from the last of a linked list
{
	int len = 0, i;
	struct Node *temp = head, *temp2 = head;

	for (i = 1; i < n; i++)					// get the n th node from the beginning
	{
		temp = temp->next;
		if (temp == NULL)
		{
			printf("\nPlease give n less than LinkedList length");
			return;
		}
	}

	for (temp; temp->next!= NULL; temp = temp->next)		// get the n th node from the last
		temp2 = temp2->next;

	temp = head;
	for (i = 1; i < n; i++)					
		temp = temp->next;

	int swap = temp->data;					// swap
	temp->data = temp2->data;
	temp2->data = swap;

	for (head; head!=NULL; head=head->next)
		printf(" %d ", head->data);

}

Node* push(struct Node *head_ref, int new_data)
{
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	if (new_node == NULL)
		printf("\nStack Overflow");
	else
	{
		new_node->data = new_data;
		new_node->next = head_ref;
		head_ref = new_node;
		return head_ref;
	}
}

int main()
{
	struct Node *head = NULL;		// Start with the empty list 

	head = push(head, 20);			// create linked list 2->5->10->35->15->4->20
	head = push(head, 4);
	head = push(head, 15);
	head = push(head, 35);
	head = push(head, 10);
	head = push(head, 5);
	head = push(head, 2);

	swap_kth_begin_last(head, 1);

	_getch();
}