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
	while (p)//��һ��ѭ��ֻ�����нڵ㸴��һ�����ԭ����Ӧ�ڵ�ĺ���
	{
		RandomListNode *temp=new RandomListNode(p->label);
		RandomListNode * next = p->next;
		p->next = temp;
		temp->next = next;
		p = next;
	}
	p = head;
	while (p)//�ڶ��θ������ָ��
	{
		if (p->random != NULL)
			p->next->random = p->random->next;
		p = p->next->next;
	}
	p = head;
	RandomListNode *q = p->next;//�ҵ�ԭʼ����ͷ����븴������ͷ�����н���
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