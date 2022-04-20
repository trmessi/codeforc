#include<iostream>
using namespace std;
int main()
{
	int i = 20;
	int* c = &i;
	int** d = &c;
	(*c)++;
	(*d)++;
	
	cout <<i ;         
}