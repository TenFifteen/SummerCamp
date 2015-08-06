#include <stdio.h>
#include <stdlib.h>

/**
 ** Definition for singly-linked list.
 **/
struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode *convert_to_list(int arr[], int n);
void free_list(struct ListNode *head);
void print_list(struct ListNode *head);

/**
 * Problem: Sort a linked list using insertion sort.
 * Solve: 3 solutions: without head node, with node and array.
 *        time: 76ms, 68ms, 20ms
 * Tips: no
 */
struct ListNode* insertionSortList(struct ListNode* head) {
	if (head == NULL) return NULL;

	struct ListNode *new_head = head;
	head = head->next;
	new_head->next = NULL;


	struct ListNode *node = head;
	while (node) {
		struct ListNode *now = node;
		node = node->next;

		int key = now->val;
		struct ListNode *new_node = new_head;
		struct ListNode *pre = new_head;
		while (new_node && new_node->val < key) {
			pre = new_node;
			new_node = new_node->next;
		}
		if (new_node == new_head) {
			now->next = new_head;
			new_head = now;
		} else {
			pre->next = now;
			now->next = new_node;
		}
	}

	return new_head;
}

/**
 * insert sort with head node
 */
struct ListNode* insertionSortList1(struct ListNode* head) {
	if (head == NULL) return NULL;

	struct ListNode *new_head = malloc(sizeof(struct ListNode));
	new_head->next = NULL;
	new_head->val = 0;
	struct ListNode *pre = new_head;

	struct ListNode *iter = head;
	while (iter) {
		struct ListNode *cur = iter;
		iter = iter->next;

		pre = new_head;
		while (pre->next && pre->next->val < cur->val) {
			pre = pre->next;
		}

		cur->next = pre->next;
		pre->next = cur;
	}

	return new_head->next;
}
ListNode *insertionSortList(ListNode *head) {
	if (!head) return head;

	vector<int> arr;
	ListNode *it = head;
	while (it) {
		arr.push_back(it->val);
		it = it->next;
	}
	sort(arr.begin(), arr.end());
	it = head;
	for (int i = 0; i < arr.size(); ++i) {
		it->val = arr[i];
		it = it->next;
	}

	return head;
}
int main()
{
	int arr[100];
	int n;
	while (~scanf("%d", &n)) {
		int i;
		for (i = 0; i < n; ++i) scanf("%d", &arr[i]);
		struct ListNode* head = convert_to_list(arr, n);
		print_list(head);
		head = insertionSortList(head);
		print_list(head);
	}

	return 0;
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
