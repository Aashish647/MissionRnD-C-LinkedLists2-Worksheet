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
	
	int count = 0, flag = 0;
	struct node *curr_node = head, *prev_node, *next_node;
	
	if (head == NULL)
	{
		return NULL;
	}
	if (K < 0)
	{
		return NULL;
	}
	
	while (curr_node != NULL)
	{
		count += 1;
		if (count == K)
		{
			struct node *new_node = (struct node*)malloc(sizeof(struct node));
			//prev_node = curr_node;
			next_node = curr_node->next;
			new_node->num = K;
			new_node->next = next_node;
			curr_node->next = new_node;
			curr_node=new_node;
			count = 0;
			flag = 1;
		}
		curr_node = curr_node->next;
	}
	return head;
}

