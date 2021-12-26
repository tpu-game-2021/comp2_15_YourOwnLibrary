#pragma once // インクルードガード

#include <stdbool.h>

// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
extern "C" {
#endif

	//片方向リストの構造体
	typedef struct NODE { struct NODE* Next; int data; int key; }NODE;
	typedef struct LIST { struct NODE* header; }LIST;
	
	void initialize_node(NODE* point, int value); //ノードを初期化
	void initialize_list(LIST* list); //リストを初期化
	void push_front(LIST* list, NODE* point); //先頭にデータを追加
	void push_next(LIST* list, NODE* node);//ノードを先頭に追加する
	void remove_front(LIST* list);//先頭のノードを削除
	void remove_next(LIST* list, NODE* point); //pointの次のノードを削除
	NODE* get_next(NODE* point);  //pointの次のノードを取得（無ければNULL）

	// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
} // extern "C"
#endif
