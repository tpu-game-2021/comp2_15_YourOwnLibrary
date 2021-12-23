#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義
#include <stdlib.h>

#include "../include/lib_func.h"

int find_Max(item* begin, const item* end)
{
	int num = end - begin;
	int Max = begin[0].key;
	for (int i = 1; i < num; i++) {
		if (begin[i].key > Max) {
			Max = begin[i].key;
		}
	}
	return Max;//最大値を返却
}

bool bin_sort(item* begin, const item* end)
{
	if (end < begin)return false;
	if (end == NULL || begin == NULL)return false;
	if (end - begin == 1)return true;//要素数が1はtrue

	int num = end - begin;
	for (int i = 0; i < num; i++) {
		if (begin[i].key == -1)return false;//キーに-1は含めない
		
		for (int j = i + 1; j < num; j++)
			if (begin[i].key == begin[j].key)return false;//同じキーがあるとダメ
	}
	
	int Max = find_Max(begin, end);
	item* bin = (item*)malloc(sizeof(item) * Max);
	
	int j = 0;
	for (int i = 0; i < Max; i++) {	//キーが-1なら要素がない
		bin[i].key = -1;
	}
	for (int i = 0; i < num; i++) {	//バケツに放り込む
		bin[begin[i].key - 1] = begin[i];
	}
	for (int i = 0; i < Max; i++) {	//バケツの最初からbeginに代入
		if (bin[i].key != -1)begin[j++] = bin[i];
	}
	free(bin);
	return true;
}