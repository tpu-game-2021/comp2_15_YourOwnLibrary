#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義
#include <stdlib.h>

#include "../include/lib_func.h"

int Change_Factorial(int wnum)
{
	if (wnum < 0 ||wnum >= 13) return -1;

	int fnum = 1;
	for (int i = 1; i <= wnum; i++) {
		 fnum = fnum * i;
	};

	return fnum;
}





