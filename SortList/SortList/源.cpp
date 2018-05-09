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
ListNode * SortList(ListNode * head)//�ݹ�ָ����ٴκϲ���������
{
	if (!head || !head->next)//����ָ�������ͷ��㣬��Ϊ�ջ���ֻ��һ���ڵ��򷵻أ����Ƿָ�����ϸ���ȣ�
	{
		return head;
	}
	if (head&&head->next)//�������������ڵ�����������
	{
		ListNode *sptr = head;
		/*��δ����Ǵ���ģ��ᵼ��nullptr->next,Ҳ���Ƕδ���*/
		
		ListNode *fptr = head;
		ListNode *temp;
		while (sptr&&fptr)
		{
			temp = sptr;
			sptr = sptr->next;
			fptr = fptr->next->next;
		}
		temp->next = nullptr;//�Ͽ�
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