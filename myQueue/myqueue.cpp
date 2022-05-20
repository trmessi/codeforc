#include"myqueue.h"
#define MAX_OP 20
int main()
{
	srand(time(0));
	Queue* q = init(MAX_OP);
	for (int i = 0; i < MAX_OP; i++)
	{
		int val = rand() % 100, op = rand() % 2;
		switch (op) {
		case 0: {
			cout << "push " << val << " to queue" << push(q, val) << endl;
		}break;
		case 1:
		{
			cout << "pop " << front(q);
			pop(q);
			cout << " from queue" << endl;
		}break;
		}
		output(q);
	}
}