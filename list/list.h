#pragma once
#ifndef __TR__
#define __TR__
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
typedef struct ListNode
{
	int data;
	struct ListNode* next;
}ListNode;
typedef struct LinkList
{
	ListNode head;
	int len;
}LinkList;
ListNode* init_listnode(int val)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = val;
	p->next = NULL;
	return p;
}
LinkList* init_linklist()
{
	LinkList* l = (LinkList*)malloc(sizeof(LinkList));
	l->head.next = NULL;
	l->len = 0;
	return l;
}
int insert(LinkList* l,int ind,int val)
{
	if (l == NULL)return 0;
	if (ind<0 || ind>l->len)return 0;
	ListNode* p = &(l->head);
	ListNode* node = init_listnode(val);
	while (ind--)
	{
		p = p->next;
	}
	node->next = p->next;
	p->next = node;
	l->len += 1;
	std::cout << "insert"<<"  ";
	return 1;
}
void clear_listnode(ListNode* node)
{
	if (node == NULL) return
	free(node);
	return;
}
int erase(LinkList* l,int ind)
{
	if (l == NULL)return 0;
	if (ind<0 || ind>=l->len)return 0;
	ListNode* p = &(l->head);
	ListNode* q;
	while (ind--)
	{
		p = p->next;
	}
	q = p->next->next;
	clear_listnode(p->next);
	p->next = q;
	l->len -= 1;
	std::cout << "earse"<<"  ";
	return 1;
}


void clear_linklist(LinkList* l)
{
	if (l == NULL)return;
	ListNode* p = l->head.next, * q;
	while (p)
	{
		q = p->next;
		clear_listnode(p);
		p = q;
	}
	free(l);
	return;
}
void output(LinkList* l)
{
	for (ListNode* p = l->head.next; p; p = p->next)
	{
		std::cout << p->data<<"->";
	}
	std::cout << "NULL" << std::endl;
}






#endif // !__TR__
