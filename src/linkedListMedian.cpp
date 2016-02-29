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
	int count = 0, temp = 1;
	while (ptr1 != NULL)
	{
		ptr1 = ptr1->next;
		count += 1;
	}
	if (count % 2 == 0)
	{
		while ((ptr2 != NULL) && (temp<(count / 2)))
		{
			ptr2 = ptr2->next;
			temp += 1;
		}
		return (ptr2->num + (ptr2->next)->num) / 2;
	}
	else
	{
		count = count / 2 ;
		while (ptr2 != NULL && temp<=count)
		{
			ptr2 = ptr2->next;
			temp += 1;
		}
		return ptr2->num;
	}
}
