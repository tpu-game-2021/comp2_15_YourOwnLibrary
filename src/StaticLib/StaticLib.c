#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義
#include <stdlib.h>
#include <malloc.h>

#include "../include/lib_func.h"



bool counting_sort(item* begin, const item* end)
{
    if (begin == NULL || end == NULL) return false;
    if (end < begin)return false;

    const int  elements = end - begin;
    int* count = (int*)malloc(sizeof(int) * (POINTS + 1));
    item* temp = (item*)malloc(sizeof(item) * elements);

    //カウンタの初期化
    for (int i = 0; i < POINTS + 1; i++)count[i] = 0;

    //キーの出現回数
    for (int i = 0; i < elements; i++)count[begin[i].key]++;

    //累積度数分布
    for (int i = 0; i < POINTS; i++)count[i + 1] += count[i];

    //度数分布に沿って配列をコピー
    for (int i = elements - 1; i >= 0; i--) {
        temp[--count[begin[i].key]] = begin[i];
    }

    //コピーした配列をbeginに代入
    for (int i = 0; i < elements; i++) {
        begin[i] = temp[i];
    }
    free(count);
    free(temp);
    return true;
}

