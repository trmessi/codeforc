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
}Queue;
Queue* init(int n)
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->data = (int*)malloc(sizeof(int) * n);
	q->head = q->tail = 0;
	q->len = n;
	return q;
}
int empty(Queue* q)
{
	return q->head == q->tail;
}
int front(Queue* q)
{
	return q->data[q->head];
}
int push(Queue* q,int val)
{
	if (q == NULL)return 0;
	if (q->tail == q->len) return 0;
	q->data[q->tail++] = val;
	return 1;
}
void pop(Queue* q)
{
	if (q == NULL)return;
	if (empty(q)) return;
	q->head++;
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
	for (int i = q->head; i < q->tail; i++)
	{
		cout << q->data[i]<<" ";
	}
	cout <<"]"<< endl;
	return;
}

#endif // !__TR__
