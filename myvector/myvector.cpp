#include"myvector.h"
int main()
{
	srand(time(0));
	int op, ind, val;
	Vector* vec = init(1);
	for (int i = 0; i < 20; i++)
	{
		op = rand() % 2;
		ind = rand() % (vec->len + 1);
		val = rand() % 100;
		switch (op)
		{
		case 0:
			{
				cout << "insert" << endl;
				
				insert(vec, ind, val);
			}break;
		case 1:
		{
			cout << "erase" << endl;
			mydelete(vec, ind);
		}break;
		}
		output(vec);
	}
	return 0;
}