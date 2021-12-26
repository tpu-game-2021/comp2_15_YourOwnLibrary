#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義
#include <stdlib.h>
#include <stdio.h>

#include "../include/lib_func.h"

int random(int x, int y)
{
	int a = 1;
	int b = 2;
	int c = NULL;
	int d = 0;
	int e = 0;

	d = rand() % 3;
	e = rand() % 3;

	if (d == 0) x = a;
	if (d == 0) x = b;
	if (d == 0) x = c;
	if (e == 0) y = a;
	if (e == 0) y = a;
	if (d == 0) y = a;
    
}

int my_func_int(int a, int b)
{
	if (a == NULL || b == NULL)
	{
		return 0;
	}

	if (a == b)
	{
		return 1;
	}

	if (a > b)
	{
		return 2;
	}

	if (b > a)
	{
		return 3;
	}
}

bool my_func_bool()
{
	return false;
}

