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
ListNode * insertionSortList(ListNode* head)
{
	if (!head)
		return nullptr;
	ListNode hd(INT_MIN);
	ListNode * cur = head;
	ListNode * pre = &hd;
	while (cur != nullptr)
	{
		ListNode * next = cur->next;
		pre = &hd;
		while (pre->next != nullptr&&pre->next->val < cur->val)
		{
			pre = pre->next;
		}
		/*直接将节点插入新链表中*/
		cur->next = pre->next;
		pre->next = cur;
		cur = next;
	}
	ListNode * pre = &hd;
	return pre->next;
}
int main()
{
	ListNode * head = CreatList();
	head = insertionSortList(head);
	printfList(head);
}