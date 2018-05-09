#include<iostream>
using namespace std;
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
RandomListNode *copyRandomList(RandomListNode *head) {
	if (head == nullptr)
	{
		return nullptr;
	}
	RandomListNode * p = head;
	while (p)//第一次循环只将所有节点复制一遍插在原来相应节点的后面
	{
		RandomListNode *temp=new RandomListNode(p->label);
		RandomListNode * next = p->next;
		p->next = temp;
		temp->next = next;
		p = next;
	}
	p = head;
	while (p)//第二次复制随机指针
	{
		if (p->random != NULL)
			p->next->random = p->random->next;
		p = p->next->next;
	}
	p = head;
	RandomListNode *q = p->next;//找到原始链表头结点与复制链表头结点进行解耦
	RandomListNode * head1 = q;
	while (p)
	{
		p->next = p->next->next;
		if (q->next)
		{
			q->next = q->next->next;
		}
		p = p->next;
		q = q->next;
	}
	return head1;
}
int main()
{
	RandomListNode  node1(1);
	RandomListNode  node2(2);
	node1.next = &node2;
	node1.random = &node2;
	node2.random = &node1;
	RandomListNode * head = copyRandomList(&node1);
	cout << head->random->label << endl;
}