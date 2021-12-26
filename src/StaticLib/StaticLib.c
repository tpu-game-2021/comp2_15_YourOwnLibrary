#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義
#include <stdlib.h>

#include "../include/lib_func.h"


//日本語の母音を数える。子音だけの場合は0
int my_func_int(const char sentence[])
{
	if (sentence[0] == NULL)return -1;//NULLだった場合-1を返す

	int i = 0, j, k;
	char check[] = "aiueo";
	int vowelcount = 0;
	for (j = 0; check[j] != '\0'; j++)
	{
		if (sentence[0] == check[j])
			vowelcount++;
	}
	i++;
	for (i; sentence[i] != '\0'; i++)
	{
		for (j = 0; check[j] != '\0'; j++)
		{
			if (sentence[i] == check[j])
			{
				for (k = 0; check[k] != '\0'; k++)
				{
					if (sentence[i-1] == check[k])
					{
						vowelcount++;
					}
				}
			}
		}
	}
	return vowelcount;
}


