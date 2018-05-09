#include<iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x) :val(x), next(nullptr) {}
};
ListNode * CreatList()
{
	ListNode *head = (ListNode *)malloc(sizeof(ListNode));
	head->next = nullptr;
	ListNode * headtemp = head;
	int a;
	cin >> a;
	while (a != -1)
	{
		ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
		temp->val = a;
		temp->next = nullptr;
		headtemp->next = temp;
		headtemp = temp;
		cin >> a;
	}
	return head->next;
}
void printfList(ListNode * head)
{
	ListNode * temp = head;
	while (temp != nullptr)
	{
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}
ListNode* reverseList(ListNode *head)/*经典的反转链表*/
{
	if (head == nullptr)
	{
		return nullptr;
	}
	ListNode *now_ptr = head;
	ListNode *pre_ptr = nullptr;
	ListNode *next_ptr = nullptr;
	while (now_ptr->next)
	{
		next_ptr = now_ptr->next;
		now_ptr->next = pre_ptr;
		pre_ptr = now_ptr;
		now_ptr = next_ptr;
	}
	now_ptr->next = pre_ptr;
	return now_ptr;
}
void reorderList(ListNode *head)
{
	if (head == nullptr || head->next == nullptr)
	{
		return;
	}
	ListNode * slow_ptr = head;
	ListNode * fast_ptr = head;
	while (fast_ptr->next&&fast_ptr->next->next)
	{
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
	}
	ListNode *head1 = slow_ptr->next;
	slow_ptr->next = nullptr;//断开
    head1 = reverseList(head1);//将slow_ptr后的节点作为头节点进行反转
	ListNode * p = head;
	ListNode * q = head1;
	while (p&&q)
	{
		ListNode *temp1;
		ListNode * temp2;
		temp1= p->next;
		temp2 = q->next;
		p->next = q;
		q->next = temp1;
		p = temp1;
		q = temp2;
	}
}
int main()
{
	ListNode * head = CreatList();
	reorderList(head);
	printfList(head);
	return 0;
}