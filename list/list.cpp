#include"list.h"
#define _MAXP_ 30
int main()
{
	LinkList* l = init_linklist();
	srand(time(0));
	for (int i = 0; i < _MAXP_; i++)
	{
		int op = rand() % 3;
		int ind = rand() % (l->len + 1);
		int val = rand() % 100;\
			switch (op)
			{
			case 0:
		
			case 1:
			{
				std::cout << val <<" to " << ind << insert(l, ind, val) << std::endl;
			}break;
			case 2:
			{
				std::cout << ind << erase(l, ind)<<std::endl;
			}break;

			}
		output(l);
		std::cout << std::endl;
	}
	return 0;
}