#include<iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x):val(x),next(nullptr){}
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
		ListNode *temp= (ListNode *)malloc(sizeof(ListNode));
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
	ListNode * temp=head;
	while (temp != nullptr)
	{
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}
ListNode * mergeSortList(ListNode* left, ListNode* right)
{
	if (!left&&right)
	{
		return right;
	}
	if (!right&&left)
	{
		return left;
	}
	else
	{
		ListNode head(0);
		ListNode *phead = &head;
		while (left&&right)
		{
			if (left->val < right->val)
			{
				phead->next = left;
				left = left->next;
			}
			else
			{
				phead->next = right;
				right = right->next;
			}
			phead = phead->next;
		}
		if (left)
		{
			phead->next = left;
		}
		if (right)
		{
			phead->next = right;
		}
		return head.next;
	}
	return nullptr;
}
ListNode * SortList(ListNode * head)//递归分割，最后再次合并有序数列
{
	if (!head || !head->next)//传入分割后的链表头结点，若为空或者只有一个节点则返回（这是分割后的最细粒度）
	{
		return head;
	}
	if (head&&head->next)//最起码有两个节点的链表的情形
	{
		ListNode *sptr = head;
		/*这段代码是错误的，会导致nullptr->next,也就是段错误*/
		
		ListNode *fptr = head;
		ListNode *temp;
		while (sptr&&fptr)
		{
			temp = sptr;
			sptr = sptr->next;
			fptr = fptr->next->next;
		}
		temp->next = nullptr;//断开
		ListNode * left = SortList(head);
		ListNode * right = SortList(sptr);
		

		return mergeSortList(left, right);
	}
}
int main()
{
	ListNode * head = CreatList();
	head=SortList(head);
	printfList(head);
}