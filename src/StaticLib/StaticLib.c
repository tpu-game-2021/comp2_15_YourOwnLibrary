#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義
#include <stdlib.h>

#include "../include/lib_func.h"



int my_func_int(val1,val2)
{
	if (val1 != val2)
	{
		val2 == val1;
		return val2;
	}
	else return val2;
}

bool my_func_bool(val1,val2)
{
	int flag = 0;
	while ( flag=0) 
	{
		if (val1 == val2)
		{
			return 0;
			flag = 1;
		}
		else
		{
			val2 == val1;
		}
	}
}

