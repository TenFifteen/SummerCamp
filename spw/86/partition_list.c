#include <stdio.h>
#include <stdlib.h>

#define N 100
struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode *convert_to_list(int arr[], int n);
void free_list(struct ListNode *head);
void print_list(struct ListNode *head);

/**
 * Problem: partition a linkedlist by the given x so that the nodes less than x
 *          come before nodes greater or equal than x.
 * Solve: two pointers.
 * Tips: if a small number come first we should make sure that the pointer 'tail_greater'
 *       must keep up with the pointer 'tail_less'
 */
struct ListNode* partition(struct ListNode* head, int x) 
{
	if (head == NULL) return NULL;

	struct ListNode *new_head = malloc(sizeof(struct ListNode));
	new_head->val = 0;
	new_head->next = NULL;
	struct ListNode *tail_less = new_head, *tail_greater = new_head;

	struct ListNode *temp = head;
	int have_greater = 0;
	while (temp) {
		struct ListNode *now = temp;
		temp = temp->next;
		if (now->val >= x) {
			have_greater = 1;
			now->next = tail_greater->next;
			tail_greater->next = now;
			tail_greater = now;
		} else {
			now->next = tail_less->next;
			tail_less->next = now;
			tail_less = now;
			if (!have_greater) {
				tail_greater = tail_less;
			}
		}
	}

	temp = new_head;
	new_head = new_head->next;
	free(temp);
	return new_head;
}

int main()
{
	int n, x;
	int arr[N];
	while (~scanf("%d %d", &n, &x)) {
		int i;
		for (i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}

		struct ListNode * head = convert_to_list(arr, n);
		print_list(head);
		head = partition(head, x);
		print_list(head);
		free_list(head);
	}
}
struct ListNode *convert_to_list(int arr[], int n)
{
	int i;

	struct ListNode *head = malloc(sizeof(struct ListNode));
	head->next = NULL;
	struct ListNode *tail = head;

	for (i = 0; i < n; ++i) {
		struct ListNode *temp = malloc(sizeof(struct ListNode));
		temp->val = arr[i];
		temp->next = NULL;

		tail->next = temp;
		tail = tail->next;
	}

	tail = head;
	head = head->next;
	free(tail);

	return head;
}

void free_list(struct ListNode *head)
{
	while (head) {
		struct ListNode* now = head;
		head = head->next;
		free(now);
	}
}
void print_list(struct ListNode *head)
{
	while (head) {
		printf("%d->", head->val);
		head = head->next;
	}
	printf("NULL\n");
}
