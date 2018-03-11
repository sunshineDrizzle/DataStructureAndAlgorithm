
#include<iostream>
#include<stdlib.h>
using namespace std;


struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};


void print_list(ListNode *head){
	if(!head){
		printf("NULL\n");
		return;
	}

	while(head){
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}


int get_list_length(ListNode *head) {
	int length = 0;
	while (head) {
		++length;
		head = head->next;
	}
	return length;
}


ListNode* forward_list(ListNode *head, int length) {
	while (head && length) {
		head = head->next;
		--length;
	}
	return head;
}


class Solution{
public:
	ListNode* reverseList(ListNode *head);
	ListNode* reverseList(ListNode *head, int m, int n);
	ListNode* mergeSortedList(ListNode *head1, ListNode *head2);
	ListNode* getIntersectionNode(ListNode *head1, ListNode *head2);
};


int main(){
	Solution solve;
	void reverse_example1(Solution *solve);
	void reverse_example2(Solution *solve);
	void merge_example(Solution *solve);
	void intersectionNode_example(Solution *solve);

	// reverse linked list
	cout << "reverse linked list\n";
	reverse_example1(&solve);
	reverse_example2(&solve);

	// merge sorted linked_list
	cout << "merge sorted linked_list";
	merge_example(&solve);

	// get intersection node
	cout << "get intersection node";
	intersectionNode_example(&solve);

	system("PAUSE");
	return 0;
}


void reverse_example1(Solution *solve){
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode *head = &a;
	a.next = &b;
	b.next = &c;
	
	cout << "before reverse:";
	print_list(head);
	ListNode *new_head = solve->reverseList(head);
	cout << "after reverse:";
	print_list(new_head);
}

void reverse_example2(Solution *solve) {
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	ListNode *head = &a;
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;

	cout << "before reverse:";
	print_list(head);
	ListNode *new_head = solve->reverseList(head, 1, 4);
	cout << "after reverse between [1, 4]:";
	print_list(new_head);
}

void merge_example(Solution *solve) {
	ListNode a(1);
	ListNode b(3);
	ListNode c(5);
	ListNode d(2);
	ListNode e(4);
	ListNode f(6);
	ListNode *head1 = &a;
	a.next = &b;
	b.next = &c;
	ListNode *head2 = &d;
	d.next = &e;
	e.next = &f;

	cout << "before merge (head1):";
	print_list(head1);
	cout << "before merge (head2):";
	print_list(head2);
	ListNode *new_head = solve->mergeSortedList(head1, head2);
	cout << "after merge:";
	print_list(new_head);
}

void intersectionNode_example(Solution *solve) {
	ListNode a1(1);
	ListNode a2(2);
	ListNode b1(3);
	ListNode b2(4);
	ListNode b3(5);
	ListNode c1(6);
	ListNode c2(7);
	ListNode c3(8);
	ListNode *head1 = &a1;
	a1.next = &a2;
	a2.next = &c1;
	ListNode *head2 = &b1;
	b1.next = &b2;
	b2.next = &b3;
	b3.next = &c1;
	c1.next = &c2;
	c2.next = &c3;

	cout << "head1:";
	print_list(head1);
	cout << "head2:";
	print_list(head2);
	ListNode *intersection_node_ptr = solve->getIntersectionNode(head1, head2);
	cout << "The intersection node value is " << intersection_node_ptr->val << endl;
}

ListNode* Solution::reverseList(ListNode *head) {
	ListNode *next = NULL;
	ListNode *new_head = NULL;
	while (head) {
		next = head->next;
		head->next = new_head;
		new_head = head;
		head = next;
	}
	return new_head;
}

ListNode* Solution::reverseList(ListNode *head, int m, int n) {
	int reversed_len = n - m + 1;
	ListNode *pre_head = NULL;
	ListNode *new_head = head;
	while (head && --m) {
		pre_head = head;
		head = head->next;
	}

	ListNode *reversed_tail = head;
	ListNode *reversed_head = NULL;
	ListNode *next = NULL;
	while (head && reversed_len--) {
		next = head->next;
		head->next = reversed_head;
		reversed_head = head;
		head = next;
	}
	reversed_tail->next = head;

	if (pre_head) {
		pre_head->next = reversed_head;
	}
	else {
		new_head = reversed_head;
	}
	return new_head;
}

ListNode* Solution::mergeSortedList(ListNode *head1, ListNode *head2) {
	ListNode temp_node(0);
	ListNode *pre = &temp_node;
	while (head1 && head2) {
		if (head1->val < head2->val) {
			pre->next = head1;
			head1 = head1->next;
		}
		else {
			pre->next = head2;
			head2 = head2->next;
		}
		pre = pre->next;
	}

	if (head1) {
		pre->next = head1;
	}
	else {
		pre->next = head2;
	}
	return temp_node.next;
}

ListNode* Solution::getIntersectionNode(ListNode *head1, ListNode *head2) {
	int head1_len = get_list_length(head1);
	int head2_len = get_list_length(head2);
	if (head1_len > head2_len) {
		int length_diff = head1_len - head2_len;
		head1 = forward_list(head1, length_diff);
	}
	else {
		int length_diff = head2_len - head1_len;
		head2 = forward_list(head2, length_diff);
	}

	while (head1 && head2) {
		if (head1 == head2) {
			return head1;
		}
		head1 = head1->next;
		head2 = head2->next;
	}
	return NULL;
}