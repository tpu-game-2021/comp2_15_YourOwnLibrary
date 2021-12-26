#include <stdio.h>
#include "../include/lib_func.h"

int my_func_int(int no);

int main(void)
{
	int no = 10;

	if (no < 1) 
	{
		printf("自然数ではありません。\n");
		return 0;
	}

	if (my_func_int(no))/*素数かどうか*/
		printf("素数です。\n");
	else
		printf("素数ではありません。\n");

	return 0;
}