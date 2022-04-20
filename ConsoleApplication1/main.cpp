#include <cstdio>
#include<iostream>
#include<unistd.h>
int main()
{
    printf("%s 向你问好!\n", "ConsoleApplication1");
    int pid=fork();
    if(pid==0)
    {
        std::cout << "father" << std::endl;
    }
    else
    {
        std::cout << "kid" << std::endl;
    }
    return 0;
}