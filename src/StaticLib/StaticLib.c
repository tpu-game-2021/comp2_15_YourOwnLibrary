#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義
#include <stdlib.h>

#include "../include/lib_func.h"


int my_func_int(int* begin, const int* end)
{
    if (begin == NULL || end == NULL) return -1;
    if (begin > end) return -1;

    long long int a, b, c, d;
    a = begin[0];

    for (int i = 1; i < end - begin; i++) {
        b = begin[i];
        if (a < 0) a *= -1;
        if (b < 0) b *= -1;
        if (a < b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        d = a * b;
        c = a % b;
        while (c != 0) {
            a = b;
            b = c;
            c = a % b;
        }
        a = d / b;
    }
	return a;
}

