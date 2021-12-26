#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義
#include <stdlib.h>

#include "../include/lib_func.h"



int my_func_int()
{
	return 0;
}

bool my_func_bool()
{
	return true;
}

bool is_same(int val1, int val2)
{
	int a = val2 % val1;
	if (a == 0)
	{
		return  true;
	}

	else {
		return false;
	}

}

int calc_BAY_3(int sum, int val1, int val2, int val3)
{
	int a, b, c, d;
	int count = 0;
	a = val1 + val2;
	b = val1 + val3;
	c = val2 + val3;
	d = val1 + val2 + val3;

	if (a % sum==0)
	{
		count = count + 1;
	}
	if (b % sum==0)
	{
		count = count + 1;
	}
	if (c % sum==0)
	{
		count = count + 1;
	}
	if (d % sum==0)
	{
		count = count + 1;
	}
	if (val1 % sum == 0)
	{
		count = count + 1;
	}
	if (val2 % sum == 0)
	{
		count = count + 1;
	}
	if (val3 % sum == 0)
	{
		count = count + 1;
	}
	return count;
}

