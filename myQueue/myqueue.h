#pragma once
#ifndef __TR__
#define __TR__
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<iostream>
using namespace std;
typedef struct Queue
{
	int* data;
	int head, tail;
	int len;
	int count;
}Queue;
Queue* init(int n)
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->data = (int*)malloc(sizeof(int) * n);
	q->head = q->tail=q->count = 0;
	q->len = n;
	return q;
}
int empty(Queue* q)
{
	return q->count == 0;
}
int front(Queue* q)
{
	return q->data[q->head];
}
int push(Queue* q,int val)
{
	if (q == NULL)return 0;
	if (q->count == q->len) return 0;
	q->data[q->tail++] = val;
	if (q->tail == q->len)q->tail -= q->len;
	q->count += 1;
	return 1;
}
void pop(Queue* q)
{
	if (q == NULL)return;
	if (empty(q)) return;
	q->head++;
	if (q->head == q->len)q->head -= q->len;
	q->count -= 1;
	return;
}
void clear(Queue* q)
{
	if (q == NULL)return;
	free(q->data);
	free(q);
	return;
}
void output(Queue* q)
{
	cout << "queue=[";
	for (int i = q->head,j=0; j<q->count; j++)
	{
		int ind = (i + j) % q->len;
		cout << q->data[ind]<<" ";
	}
	cout <<"]"<< endl;
	return;
}

#endif // !__TR__
