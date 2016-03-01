/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>
struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {


	if (head1 == NULL)
	{
		return head2;
	}
	if (head2 == NULL)
	{
		return head1;
	}

	struct node *head11 = head1, *head22 = head2, *merger_head, *curr_node;

	if (head22->num <= head11->num)
	{
		merger_head = head22;
		head22 = head22->next;
	}
	else
	{
		merger_head = head11;
		head11 = head11->next;
	}
	curr_node = merger_head;
	while ((head11!=NULL) && (head22!=NULL))
	{
		if (head22->num <= head11->num)
		{
			curr_node->next = head22;
			head22 = head22->next;
			//curr_node = curr_node->next;
		}
		else
		{
			curr_node->next = head11;
			head11 = head11->next;
			//curr_node = curr_node->next;
		}
		curr_node = curr_node->next;
	}
	while (head11!=NULL)
	{
		curr_node->next = head11;
		head11 = head11->next;
		curr_node = curr_node->next;
	}
	while (head22!=NULL)
	{
		curr_node->next = head22;
		head22 = head22->next;
		curr_node = curr_node->next;
	}
	return merger_head;
}
