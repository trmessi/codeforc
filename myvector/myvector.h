#pragma once
#ifndef __TR__
#define __TR__
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
typedef struct Vector
{
	int* data;
	int size, len;
}Vector;
Vector* init(int n)
{
	Vector* vec = (Vector*)malloc(sizeof(Vector));
	vec->data = (int*)malloc(sizeof(int) * n);
	vec->size = n;
	vec->len = 0;
	return vec;
}
int expand(Vector* vec)
{
	vec->size *= 2;
	vec->data= (int *)realloc(vec->data, sizeof(int) * vec->size);//
	return 1;
}
int insert(Vector* vec,int ind,int val)
{
	if (vec == NULL)return 0;
	if (vec->len == vec->size)
	{
		if (!expand(vec)) return 0;
	}
	if (ind<0 || ind>vec->len) return 0;
	for (int i = vec->len - 1; i > ind; i--)
	{
		vec->data[i] = vec->data[i - 1];

	}
	vec->data[ind] = val;
	vec->len += 1;
	return 1;
}
int mydelete(Vector* vec,int ind)
{
	if (vec == NULL)return 0;
	if (vec->len == 0) return 0;
	if (ind<0 || ind>vec->len) return 0;
	for (int i = ind+1; i < vec->len - 1; i++)
	{
		vec->data[i - 1] = vec->data[i];
	}
	vec->len -= 1;
	return 1;
}
void output(Vector* vec)
{
	cout << "length" << vec->len<<"  "<< endl;
	for (int i = 0; i < vec->len; i++)
	{
		cout << vec->data[i] << ",";
	}
}
void clear(Vector* vec)
{
	if (vec == NULL) return;
	free(vec->data);
	free(vec);
	return;
}


#endif // !__TR__
