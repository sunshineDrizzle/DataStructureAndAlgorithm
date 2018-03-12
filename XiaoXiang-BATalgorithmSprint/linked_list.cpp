
#include<iostream>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
using namespace std;


struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

struct RandomListNode {
	int val;
	RandomListNode *next, *random;
	RandomListNode(int x): val(x), next(NULL), random(NULL){}
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

void print_random_list(RandomListNode *head) {
	while (head) {
		printf("val: %d; ", head->val);
		if (head->random) {
			printf("random: %d\n", head->random->val);
		}
		else {
			printf("random: NULL\n");
		}
		head = head->next;
	}
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
	ListNode* detectCircleNode(ListNode *head);
	ListNode* partition(ListNode *head, int x);
	RandomListNode* copyRandomList(RandomListNode *head);
};


int main(){
	Solution solve;
	void reverse_example1(Solution *solve);
	void reverse_example2(Solution *solve);
	void merge_example(Solution *solve);
	void intersectionNode_example(Solution *solve);
	void detectCircleNode_example(Solution *solve);
	void partition_example(Solution *solve);
	void copyRandomList_example(Solution *solve);

	// reverse linked list
	cout << "***reverse linked list***\n";
	reverse_example1(&solve);
	reverse_example2(&solve);

	// merge sorted linked_list
	cout << "\n***merge sorted linked_list***\n";
	merge_example(&solve);

	// get intersection node
	cout << "\n***get intersection node***\n";
	intersectionNode_example(&solve);

	// detect circle node
	cout << "\n***detect circle node***\n";
	detectCircleNode_example(&solve);

	// partition linked list
	cout << "\n***partition linked list***\n";
	partition_example(&solve);

	// copy random linked list
	cout << "\n***copy random linked list***\n";
	copyRandomList_example(&solve);

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

void detectCircleNode_example(Solution *solve) {
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
	e.next = &c;

	ListNode *circle_node_ptr = solve->detectCircleNode(head);
	cout << "The circle node's value is:" << circle_node_ptr->val << endl;
}

void partition_example(Solution *solve) {
	ListNode a(1);
	ListNode b(5);
	ListNode c(4);
	ListNode d(3);
	ListNode e(6);
	ListNode f(2);
	ListNode *head = &a;
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;

	cout << "before partition:";
	print_list(head);
	ListNode *new_head = solve->partition(head, 3);
	cout << "after partition:";
	print_list(new_head);
}

void copyRandomList_example(Solution *solve) {
	RandomListNode a(1);
	RandomListNode b(2);
	RandomListNode c(3);
	RandomListNode d(4);
	RandomListNode e(5);
	RandomListNode *head = &a;
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	a.random = &e;
	c.random = &b;
	e.random = &c;

	cout << "head (" << head << "):\n";
	print_random_list(head);
	RandomListNode *new_head = solve->copyRandomList(head);
	cout << "new head (" << new_head << "):\n";
	print_random_list(new_head);
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

ListNode* Solution::detectCircleNode(ListNode *head) {
	set<ListNode *> node_set;
	while (head) {
		if (node_set.find(head) != node_set.end()) {
			return head;
		}
		node_set.insert(head);
		head = head->next;
	}
	return NULL;
}

ListNode* Solution::partition(ListNode *head, int x) {
	ListNode less_head(0);
	ListNode *less_ptr = &less_head;
	ListNode more_head(0);
	ListNode *more_ptr = &more_head;
	while (head) {
		if (head->val < x) {
			less_ptr->next = head;
			less_ptr = less_ptr->next;
		}
		else {
			more_ptr->next = head;
			more_ptr = more_ptr->next;
		}
		head = head->next;
	}
	less_ptr->next = more_head.next;
	more_ptr->next = NULL;
	return less_head.next;
}

RandomListNode* Solution::copyRandomList(RandomListNode *head) {
	RandomListNode *node_ptr = head;
	map<RandomListNode *, int> node2id_map;
	vector<RandomListNode *> id2node_vec;
	for (int i = 0; node_ptr; ++i, node_ptr = node_ptr->next) {
		node2id_map[node_ptr] = i;
		id2node_vec.push_back(new RandomListNode(node_ptr->val));
	}

	node_ptr = head;
	id2node_vec.push_back(NULL);
	for (int i = 0; node_ptr; ++i, node_ptr = node_ptr->next) {
		id2node_vec[i]->next = id2node_vec[i + 1];
		if (node_ptr->random) {
			int random_id = node2id_map[node_ptr->random];
			id2node_vec[i]->random = id2node_vec[random_id];
		}
	}
	return id2node_vec[0];
}
