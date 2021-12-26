#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義
#include <stdlib.h>

#include "../include/lib_func.h"

//ノードの初期化
void initialize_node(NODE* point, int key)
{
	point->Next = NULL;
	point->data = key;
}

//リストの初期化
void initialize_list(LIST* list)
{
	list->header = NULL;
}

//先頭にデータを追加
void push_front(LIST* list, NODE* point)
{
	if (point == NULL || list == NULL) return;
	point->Next = list->header;
	list->header = point;
}

//ノードに追加をする
void push_next(LIST* list, NODE* node)
{
	push_front(list, node);
}

//先頭のノードを削除
void remove_front(LIST* list)
{
	if (list == NULL) return;
	NODE* tmp = list->header->Next;
	list->header = tmp;
}

//pointの次のノードを削除
void remove_next(LIST* list, NODE* point)
{
	if (list == NULL || point == NULL || point->Next == NULL) return;
	point->Next = point->Next->Next;
}

//pointの次のノードを取得
NODE* get_next(NODE* point)
{
	if (!point) return NULL;
	return point->Next;
}
