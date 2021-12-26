#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義
#include <stdlib.h>

#include "../include/lib_func.h"

int my_func_int(int no)
{
    int i;

    if (no < 1)
    {
        return 0;
    }

    for (i = 2; i < no; i++) 
    {
        if (no % i == 0) 
        {
            return 0;
        }
    }
    return 1;
}