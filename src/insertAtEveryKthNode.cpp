/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head == NULL)
	{
		return NULL;
	}
	if (K < 0)
	{
		return NULL;
	}
	int count = 1, flag = 0;
	struct node *curr_node = head, *temp_node1 = NULL, *temp_node2 = NULL, *new_node = NULL;
	while (curr_node->next != NULL)
	{
		if (count == K)
		{
			temp_node1 = curr_node;
			temp_node2 = curr_node->next;
			new_node->num = K;
			new_node->next = temp_node2;
			temp_node1->next = new_node;
			count = 0;
			flag = 1;
		}
		count++;
		curr_node = curr_node->next;
	}
	if (flag == 0)
	{
		return NULL;
	}
}

