#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義
#include <stdlib.h>

#include "../include/lib_func.h"


int judge_prime(int num)
{
	int i;  // ループの添え字
	int flag = 0;  // 素数判定用

	if (num < 1) return false;

	for (i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			flag = 1;
			return flag;
		}
	}

	if (flag == 0)  return flag;
}

int judge_prime_many(int num)
{
	int i, j;       // ループの添え字
	int flag = 0;   // 素数判定用
	int count = 0;  // 素数の個数のカウント

	if (num < 1)  return false;

	for (i = 2; i < num; i++)
	{
		flag = 0;  // 判定の初期化用

		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				flag = 1;
			}
		}

		if (flag == 0)
		{
			count++;
		}
	}

	return count;
}



