/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head == NULL)
	{
		return -1;
	}
	struct node *ptr1 = head;
	struct node *ptr2 = head;
	struct node *ptr3 = head;
	int count = 0, temp = 0, sum = 0;
	while ((ptr1->next != NULL)&& (ptr2->next!=NULL))
	{
		temp = ptr2->num;
		ptr1 = ptr1->next->next;
		ptr2 = ptr2->next;
		count++;
	}
	if ((count % 2) == 1)
	{
		while (ptr3->next != ptr2)
		{
			ptr3 = ptr3->next;
		}
		sum = ptr3->num;
		temp = ptr2->num;
		sum = sum + temp;
		sum = sum / 2;
		return sum-1;
	}
	else
	{
		return ptr2->num;
	}
}
